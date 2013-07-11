#ifndef LOGGER
#define LOGGER
#pragma once
#include <string>
namespace game {

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
		
	void debug(const char* text);
	void info(const char* text);
	void error(const char* text);
	void setLevel(LEVELS lvl);
	void setConsole(bool console);


private:
	static Logger* instance;
	bool console;
	LEVELS level;

	

	FILE *logfile;
	Logger(void);
	~Logger(void);
	void textOut(const char* text);
	void textOut(const char* text, COLORS color); // no need atm

};


#endif
}