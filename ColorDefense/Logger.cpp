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
	streamoff begin, end;
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

void Logger::textOut(ostringstream& text) {
	if(fileSize > MAX_FILESIZE) {
		logfile.close();
		logfile.open(FILENAME, ios::out);
		fileSize = 0;
	}
	logfile << text;
	if(console) cout << text;
	fileSize += text.tellp();
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
	// put_time is not implemented in libstdc++ yet, for whatever reason
#else
	auto result = "N/A";
#endif
	std::stringstream ss;
	ss << result;
	return ss.str();
}

void Logger::info(ostringstream& text) {
	info(text.str());
}

void Logger::debug(ostringstream& text) {
	debug(text.str());
}

void Logger::error(ostringstream& text) {
	error(text.str());
}

//ostream& operator<<(ostream& str, Logger& logger) {
//	logger.info(str);
//}

Logger* Logger::instance = nullptr;