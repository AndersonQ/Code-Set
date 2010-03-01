/*
 * =====================================================================================
 *
 *       Filename:  Men.cpp
 *
 *    Description:  Aloca emfileira itens até acabar a memória do computador
 *
 *
 *        Version:  1.0
 *        Created:  28-02-2010 13:00:04
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
	FilaEnc<char> f;
	bool ok = true;
	unsigned double i = 0;

	cout << endl;

	while(ok != false )// false)
	{
		try
		{
			f.insere(i);
			i = i + 1;
		}
		catch(logic_error)
		{
			ok = false;
		}
	}
	cout << "Número de células alocadas = " << i << endl;
}
