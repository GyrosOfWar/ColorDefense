#include "stdafx.h"
#include "Logger.hpp"
#include <string>
using namespace game;

Logger::Logger(void)
{
	#ifdef WIN32
	fopen_s(&logfile, "log.log", "w");
	#else
	logfile = fopen("log.log", "w");
	#endif
	setLevel(LEVELS::INFO);
	console = true;
}


Logger::~Logger(void)
{
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

void Logger::textOut(const char* text) {
	fprintf(logfile, text);
	fflush(logfile);
	if(console) printf(text);
}


void Logger::info(const char* text) {
	if(level <= LEVELS::INFO) {
		textOut("INFO: ");
		textOut(text);
		textOut("\n");
	}

}

void Logger::debug(const char* text) {
	if(level <= LEVELS::DEBUG) {
		textOut("DEBUG: ");
		textOut(text);
		textOut("\n");
	}
}

	
void Logger::error(const char* text) {
	if(level <= LEVELS::ERROR) {
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


Logger* Logger::instance = 0;