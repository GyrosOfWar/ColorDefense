#include "stdafx.h"
#include "Logger.hpp"

Logger::Logger(void) {
	// Open file log.log with write access 
	// and append to the already existing content
	logfile.open("log.log", ios::out | ios::app); 
	setLevel(LEVELS::INFO);
	console = true;
	fileSize = getFileLength("log.log");
	cout << fileSize << endl;
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
	logfile << text;
	if(console) cout << text;
	fileSize += text.length();
}


void Logger::info(const string& text) {
	if(level <= LEVELS::INFO) {
		//textOut(getTimeStamp());
		//textOut(": ");
		textOut("INFO: ");
		textOut(text);
		textOut("\n");
	}

}

void Logger::debug(const string& text) {
	if(level <= LEVELS::DEBUG) {
		//textOut(getTimeStamp());
		//textOut(": ");
		textOut("DEBUG: ");
		textOut(text);
		textOut("\n");
	}
}

	
void Logger::error(const string& text) {
	if(level <= LEVELS::ERROR) {
		//textOut(getTimeStamp());
		//textOut(": ");
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

void Logger::getTimeStamp(const ostream& output) {
	time_t now = time(NULL);
	//output << put_time(localtime(&now), "%F");
	// TODO
}

Logger* Logger::instance = nullptr;