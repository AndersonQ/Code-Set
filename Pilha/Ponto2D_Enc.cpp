/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Test das pilhas
 *
 *        Version:  1.0
 *        Created:  24-02-2010 19:05:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include "PilhaEnc.h"

using namespace std;

using ED::PilhaEnc;

struct Ponto2D
{
	int x, y;
};

int main()
{
	PilhaEnc<Ponto2D> p;
	Ponto2D pt;

	int t;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pt.x = i;
			pt.y = j;
			p.empilha(pt);
		}
	}

	cout << "Pilha vazia = " << p.vazia() << endl;
	cout << "Tamanho da Pilha = "<< p.tamanho() << endl;

	t = p.tamanho();

	for (int i = 0; i < t; i++)
	{
		pt = p.desempilha();
		cout << "(" << pt.x << "," << pt.y << ")" << endl;
	}
}
