#include "stdafx.h"
#include "Logger.hpp"
#include <string>

using namespace std;


Logger::Logger(void)
{
	logfile = fopen("log.log", "w");
	setLevel(LEVELS::INFO);
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
}


void Logger::info(const char* text) {
	if(level >= LEVELS::INFO) {
		textOut(text);
	}

}

void Logger::debug(const char* text) {
	if(level >= LEVELS::DEBUG) {
		textOut(text);
	}
}

	
void Logger::error(const char* text) {
	if(level >= LEVELS::ERROR) {
			textOut(text);
		}
}

void Logger::setLevel(LEVELS lvl) {
	this->level = lvl;
}