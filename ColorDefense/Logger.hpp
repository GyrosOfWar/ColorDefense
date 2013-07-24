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
static const string FILENAME = "log.log";

class Logger {
public:
	static Logger* get(void);
	static void del(void);

	void debug(const string& text);
	void info(const string& text);
	void error(const string& text);
	void setLevel(LEVELS lvl);
	void setConsole(bool console);

	void debug(ostringstream& text);
	void info(ostringstream& text);
	void error(ostringstream& text);

private:
	Logger(void);
	~Logger(void);

	static const size_t MAX_FILESIZE = 1024 * 1024; // 1MB
	static Logger* instance;

	bool console;
	LEVELS level;
	size_t fileSize;
	ofstream logfile;

	void textOut(const string& text);
	void textOut(const string& text, COLORS color); // no need atm
	void textOut(ostringstream& text);

	long getFileLength(const string& path);
	string getTimeStamp();
};
#endif
