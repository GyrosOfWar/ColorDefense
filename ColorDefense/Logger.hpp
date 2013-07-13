#ifndef LOGGER
#define LOGGER
#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>

using namespace std;

enum COLORS {
	BLACK,
	RED,
	BLUE,
	GREEN
}; //no need atm

enum LEVELS {
	INFO,
	DEBUG,	
	ERROR
};

class Logger {
public:
	static Logger* get(void);
	static void del(void);
		
	void debug(const string& text);
	void info(const string& text);
	void error(const string& text);
	void setLevel(LEVELS lvl);
	void setConsole(bool console);

private:
	static const int MAX_FILESIZE = 1024 * 1024; // 1MB
	static Logger* instance;
	bool console;
	LEVELS level;
	long fileSize;

	ofstream logfile;
	Logger(void);
	~Logger(void);
	void textOut(const string& text);
	void textOut(const string& text, COLORS color); // no need atm

	long getFileLength(const string& path);

	void Logger::getTimeStamp(const ostream& output);

};


#endif
