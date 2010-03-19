#include <iostream>
#include <ctime>
extern "C" {
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>
#include <math.h>
}

#include "timer.h"


/**
 * Constructor.
 */
Timer::Timer() {
	reset();
}

/**
 * Resets the timer, setting elapsed time to zero.
 */
void
Timer::reset() {
	struct tms time;
	times( &time );
	elapsed_t = 0;
	start_t = time.tms_utime;
	running = true;
}

/**
 * Starts the timer again after stopping it.
 *
 * Elapsed time will NOT be set to zero!
 */
void
Timer::start() {
	struct tms time;
	times( &time );
	start_t = time.tms_utime;
	running = true;
}

/**
 * Stops the timer.
 *
 * Does NOT clear elapsed time.
 */
void
Timer::stop() {
	struct tms time;
	times( &time );
	clock_t current_t = time.tms_utime;
	elapsed_t += current_t - start_t;
	running = false;
}

/**
 * Gives the elapsed time, in seconds.
 *
 * @return A double with the time.
 */
long double
Timer::elapsed_time() {
	if (running) {
		struct tms time;
		times( &time );
		clock_t current_t = time.tms_utime;
		long double tot_secs = (long double) (elapsed_t + current_t - start_t) / (long double) sysconf(_SC_CLK_TCK);
		return tot_secs;
	} else {
		return (long double) elapsed_t / (long double) sysconf(_SC_CLK_TCK);
	}
}

/**
 * Returns the current value of the clock, in clock_t.
 *
 * @return A clock_t value with the current time (as given by the times() C function call).
 */
clock_t
Timer::get_time() {
	struct tms time;
	times( &time );
	return time.tms_utime;
}

