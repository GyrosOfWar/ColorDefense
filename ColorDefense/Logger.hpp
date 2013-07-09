#pragma once
#include <string>

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


private:
	static Logger* instance;
	
	LEVELS level;

	void setLevel(LEVELS lvl);

	FILE *logfile;
	Logger(void);
	~Logger(void);
	void textOut(const char* text);
	void textOut(const char* text, COLORS color); // no need atm

};

Logger* Logger::instance = 0;