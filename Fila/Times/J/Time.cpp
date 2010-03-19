/*
 * =====================================================================================
 *
 *       Filename:  secTime.cpp
 *
 *    Description:  Mede o tempo para enfileirar 1.000.000, 5.000.000 10.000.000 e 20.000.000 de inteiros com a biblioteca "PilhaSeq.h"
 *
 *
 *        Version:  1.0
 *        Created:  28-02-2010 09:47:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>
#include "SeqFila.h"
#include "EncFila.h"

using ED::FilaSeq;
using ED::FilaEnc;

using namespace std;

void e_insere(int n);
void s_insere(int n);

int main(int argc, char*argv[])
{
	//double te1, te5, te10, te20, ts1, ts5, ts10, ts20;

	s_insere(1);
	e_insere(1);
	s_insere(5);
	e_insere(5);
	s_insere(10);
	e_insere(10);
	s_insere(20);
	e_insere(20);
	
	
}

void e_insere(int n)
{
	FilaEnc<int> e;

	struct timeval tv1, tv2;
	double t;

	n *= 1000000;

	cout << "Enfileirando " << n << " elementos numa fila sequencial\n";
	gettimeofday(&tv1, NULL);
	//t = clock();
	
	for (int i = n; i < n; i++)
		e.insere(i);
	
	gettimeofday(&tv2, NULL);

	t = ((tv2.tv_sec - tv1.tv_sec)*1000000 + (tv2.tv_usec - tv1.tv_usec));

	cout << "Tempo =  " << t/1000 << "ms\n\n";
}

void s_insere(int n)
{
	FilaSeq<int> s(n);

	struct timeval tv1, tv2;
	double t;

	n *=1000000;

	cout << "Enfileirando " << n << " elementos numa fila sequencial\n";
	gettimeofday(&tv1, NULL);
	t = clock();
	
	for (int i = n; i < n; i++)
		s.insere(i);
	
	gettimeofday(&tv2, NULL);

	t = ((tv2.tv_sec - tv1.tv_sec)*1000000 + (tv2.tv_usec - tv1.tv_usec));

	cout << "Tempo =  " << t/1000 << "ms\n\n";
}
