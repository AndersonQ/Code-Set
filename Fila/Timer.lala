/*
 * =====================================================================================
 *
 *       Filename:  Timer.h
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  08-03-2010 12:08:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include <ctime>
extern "C" {
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>
#include <math.h>
}
#include "Timer.cpp"

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
