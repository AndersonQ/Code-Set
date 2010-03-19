#ifndef TIMER_H
#define TIMER_H

#include <ctime>

/**
 * This class implements a simple timer.
 */
class Timer {
private:
	clock_t  start_t;
	clock_t elapsed_t;
	bool running;
public:
	Timer();
	void reset();
	void start();
	void stop();
	long double elapsed_time();
	clock_t get_time();
};

#endif
