/*
 * =====================================================================================
 *
 *       Filename:  Timer.cpp
 *
 *    Description:  Libary of stopwtcher
 *
 *
 *        Version:  1.0
 *        Created:  07-03-2010 18:43:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */
//#ifndef TIMER_H
//#define TIMER_H

//#include <iostream>
#include <ctime>
extern "C" {
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>
#include <math.h>
}

class Timer
{

	private:
		clock_t start_st;
		clock_t start_ut;
		clock_t elapsed_ut;
		clock_t elapsed_st;
		bool running;

	public:
		void reset();
		void start();
		void stop();
		long double elapsed_stime();
		long double elapsed_utime();
};

void
Timer::reset()
{
	struct tms time;

	times( &time );
	start_st = start_ut = elapsed_st = elapsed_ut = 0;
	running = true;
}

void
Timer::start()
{
	struct tms time;
	times( &time );

	start_ut = time.tms_utime;
	start_st = time.tms_stime;
	running = true;
}

void
Timer::stop()
{
	struct tms time;
	times(&time);
	
	elapsed_st = time.tms_stime;
	elapsed_ut = time.tms_utime;

	running = false;
	//reset();
}

long double
Timer::elapsed_utime()
{
	struct tms time;
	long double running_t;

	if (running)
	{
		times(&time);
		elapsed_ut = time.tms_utime;
		running_t = (long double) (elapsed_ut - start_ut) / (long double) sysconf(_SC_CLK_TCK);

		return running_t;
	}
	else
	{
		running_t = (long double) (elapsed_ut - start_ut) / (long double) sysconf(_SC_CLK_TCK);

		return running_t;
	}
}

long double
Timer::elapsed_stime()
{
	struct tms time;
	long double running_t;

	if (running)
	{
		times(&time);
		elapsed_st = time.tms_stime;
		running_t = (long double) (elapsed_st - start_st) / (long double) sysconf(_SC_CLK_TCK);

		return running_t;
	}
	else
	{
		running_t = (long double) (elapsed_st - start_st) / (long double) sysconf(_SC_CLK_TCK);

		return running_t;
	}
}


