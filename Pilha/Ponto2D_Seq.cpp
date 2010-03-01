/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Test das pilhas
 *
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
#include  "PilhaSeq.h"

using namespace std;

using ED::PilhaSeq;

struct Ponto2D
{
	int x, y;
};

int main()
{
	PilhaSeq<Ponto2D> p(50);
	Ponto2D pt;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pt.x = i;
			pt.y = j;
			p.empilha(pt);
		}
	}

	cout << "Pilha Vazia = " << p.vazia() << endl;
	cout << "Pilha Cheia = " << p.cheia() << endl;
	cout << "Tamanho da Pilha = " << p.tamanho() << endl;

	for (int i = 0; i < 25; i++)
	{
		pt = p.desempilha();
		cout << pt.x << "," << pt.y << endl;
	}

	cout << "Pilha Vazia = " << p.vazia() << endl;
	cout << "Pilha Cheia = " << p.cheia() << endl;
	cout << "Tamanho da Pilha = " << p.tamanho() << endl;
}
