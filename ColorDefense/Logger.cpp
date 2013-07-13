#include "stdafx.h"
#include "Logger.hpp"

Logger::Logger(void) {
	// Open file log.log with write access 
	// and append to the already existing content
	logfile.open(FILENAME, ios::out | ios::app); 
	setLevel(LEVELS::INFO);
	console = true;
	fileSize = getFileLength(FILENAME);
}


Logger::~Logger(void) {
	logfile.close();
}

long Logger::getFileLength(const string& path) {
	long begin, end;
	ifstream myfile (path);
	begin = myfile.tellg();
	myfile.seekg (0, ios::end);
	end = myfile.tellg();
	myfile.close();
	return (end-begin);
}

Logger* Logger::get(void) {
	if(!instance) instance = new Logger;
	return instance;
}

void Logger::del(void) {
	if(instance) {
		delete(instance);
		instance = NULL;
	}
}

void Logger::textOut(const string& text) {
	// TODO flush output, maybe?
	// Clear the log file
	if(fileSize > MAX_FILESIZE) {
		logfile.close();
		logfile.open(FILENAME, ios::out);
		fileSize = 0;
	}
	logfile << text;
	if(console) cout << text;
	fileSize += text.length();
}


void Logger::info(const string& text) {
	if(level <= LEVELS::INFO) {
		textOut(getTimeStamp());
		textOut(": ");
		textOut("INFO: ");
		textOut(text);
		textOut("\n");
	}

}

void Logger::debug(const string& text) {
	if(level <= LEVELS::DEBUG) {
		textOut(getTimeStamp());
		textOut(": ");
		textOut("DEBUG: ");
		textOut(text);
		textOut("\n");
	}
}

	
void Logger::error(const string& text) {
	if(level <= LEVELS::ERROR) {
		textOut(getTimeStamp());
		textOut(": ");
		textOut("ERROR: ");
		textOut(text);
		textOut("\n");
	}
}

void Logger::setLevel(LEVELS lvl) {
	this->level = lvl;
}

void Logger::setConsole(bool console) {
	this->console = console;
}

string Logger::getTimeStamp() {
	time_t now = time(nullptr);
	tm* tm = localtime(&now);
	#ifdef WIN32
	auto result = put_time(tm, "%d.%m.%y %H:%M");
	#else
	auto result = "N/A";
	#endif
	std::stringstream ss;
	ss << result;
	return ss.str();
}

Logger* Logger::instance = nullptr;