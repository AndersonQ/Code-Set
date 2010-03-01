/*
 * =====================================================================================
 *
 *       Filename:  TesFilaSeq.cpp
 *
 *    Description:  Testa FilaSeq.h
 *
 *        Version:  1.0
 *        Created:  24-02-2010 21:50:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include "SeqFila.h"

using ED::FilaSeq;

using namespace std;

int main()
{
	FilaSeq<int> f(30);
	
	int t;

	for (int i = 0; i < 30; i++)
		f.insere(i);

	t = f.tamanho();

	cout <<endl << endl << "Pilha Vazia = " << f.vazia() << endl;
	cout << "Pila Cheia = " << f.cheia() << endl;
	cout << "Tamanho da pilha = " << f.tamanho() << endl;

	for (int i = 0; i < 30; i ++)
		cout << "Retirado = " << f.retira() << endl;

	cout << "Pilha Vazia = " << f.vazia() << endl;
	cout << "Pila Cheia = " << f.cheia() << endl;
	cout << "Tamanho da pilha = " << f.tamanho() << endl << endl << endl;

}
