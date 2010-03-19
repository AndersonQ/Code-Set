/*
 * =====================================================================================
 *
 *       Filename:  Tempo.cpp
 *
 *    Description:  Mede Tempos pra enfileirar em fila sequencial e estática
 *
 *
 *        Version:  1.0
 *        Created:  08-03-2010 12:16:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

//#include <iostream>
#include <stdio.h>
#include "Timer.cpp"
#include "EncFila.h"
#include "SeqFila.h"

using ED::FilaEnc;
using ED::FilaSeq;
using namespace std;

Timer::Timer stopw;

void Enc(int n);
void Seq(int n);
	
int
main()
{
	Timer::Timer total;
	total.start();

	Seq(1000000);
	stopw.elapsed_stime();

	printf("Enfileirados sequenciamente 1.000.000 elementos em %.4Lf segundos\n\n", stopw.elapsed_stime());

	Enc(1000000);
	stopw.elapsed_stime();

	printf("Enfileirados Enc 1.000.000 elementos em %.4Lf segundos\n\n", stopw.elapsed_stime());

}

void
Seq(int n)
{
	FilaSeq<bool> f(n);
	
	stopw.start();

	for (int i = 0; i < n; i++)
		f.insere(1);		
	
	stopw.stop();
}

void
Enc(int n)
{

	FilaEnc<bool> f;
	
	stopw.start();

	for (int i = 0; i < n; i++)
		f.insere(1);
	
	stopw.stop();
}
