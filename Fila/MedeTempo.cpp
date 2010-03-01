/*
 * =====================================================================================
 *
 *       Filename:  t.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  28-02-2010 08:22:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char *argv[])
{
	struct timeval tv1, tv2;
	double t1, t2;

	cout << "Processo pai, pid = " << getpid() << "\n";

	if (fork() == 0)
	{
		cout << "Processo filho, pid = " << getpid() << endl;
		gettimeofday(&tv1, NULL);
		
		system("ls");

		gettimeofday(&tv2, NULL);

		t1 = (-(tv1.tv_sec + tv1.tv_usec) + (tv2.tv_sec + tv2.tv_usec)) / 1000000.0;

		cout << "O Processo filho ls demorou " << t1 << endl;
	}
	else 
		cout << "lalalalal\n\n";
}
