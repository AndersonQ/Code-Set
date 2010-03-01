/*
 * =====================================================================================
 *
 *       Filename:  EncFilaTes.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  26-02-2010 11:14:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include "EncFila.h"

using ED::FilaEnc;
using namespace std;

int main()
{
	FilaEnc<int> f;

	//queue
	for (int i = 0; i < 30; i++)
		f.insere(i);

	cout << endl << "Fila Vazia = " << f.vazia() << endl;
	cout << "Tamanho da fila = " << f.tamanho() << endl << endl;

	//dequeue
	for (int i = 0; i < 30; i++)
		cout << f.retira() << endl;

	cout << endl << "Fila Vazia = " << f.vazia() << endl;
	cout << "Tamanho da fila = " << f.tamanho() << endl << endl;

	return 0;
}

