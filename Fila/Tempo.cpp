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

//////////////////////////////////////////////////////1.000.000///////////////////////////////////////////////////////
	Seq(1000000);
	stopw.elapsed_stime();

	printf("\n\nEnfileirados 1.000.000 elementos em %.4Lf segundos com Fila Sequencial\n", stopw.elapsed_utime());

	Enc(1000000);
	stopw.elapsed_stime();

	printf("Enfileirados 1.000.000 elementos em %.4Lf segundos com Fila Encadeada\n", stopw.elapsed_utime());

//////////////////////////////////////////////////////5.000.000///////////////////////////////////////////////////////
	Seq(5000000);
	stopw.elapsed_stime();

	printf("\n\nEnfileirados 5.000.000 elementos em %.4Lf segundos com Fila Sequencial\n", stopw.elapsed_utime());

	Enc(5000000);
	stopw.elapsed_stime();

	printf("Enfileirados 5.000.000 elementos em %.4Lf segundos com Fila Encadeada\n", stopw.elapsed_utime());

//////////////////////////////////////////////////////10.000.000///////////////////////////////////////////////////////
	Seq(10000000);
	stopw.elapsed_stime();

	printf("\n\nEnfileirados 10.000.000 elementos em %.4Lf segundos com Fila Sequencial\n", stopw.elapsed_utime());

	Enc(10000000);
	stopw.elapsed_stime();

	printf("Enfileirados 10.000.000 elementos em %.4Lf segundos com Fila Encadeada\n", stopw.elapsed_utime());

//////////////////////////////////////////////////////20.000.000///////////////////////////////////////////////////////
	Seq(20000000);
	stopw.elapsed_stime();

	printf("\n\nEnfileirados 20.000.000 elementos em %.4Lf segundos com Fila Sequencial\n", stopw.elapsed_utime());

	Enc(20000000);
	stopw.elapsed_stime();

	printf("Enfileirados 20.000.000 elementos em %.4Lf segundos com Fila Encadeada\n", stopw.elapsed_utime());

	printf("\n\nTempo total gasto pelo programa: %.4Lf segundos\n\n", total.elapsed_utime());

}

void
Seq(int n)
{
	FilaSeq<int> f(n);
	
	stopw.start();

	for (int i = 0; i < n; i++)
		f.insere(i);		
	
	stopw.stop();
}

void
Enc(int n)
{

	FilaEnc<int> f;
	
	stopw.start();

	for (int i = 0; i < n; i++)
		f.insere(i);
	
	stopw.stop();
}
