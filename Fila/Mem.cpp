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
	FilaEnc<bool> f;
	bool ok = true;
	double i = 0;

	cout << endl;

	while(ok != false )// false)
	{
		try
		{
			f.insere(1);
			i = i + 1;
			cout << i << endl;
		}
		catch(logic_error)
		{
			ok = false;
		}
	}
	cout << "Número de células alocadas = " << i << endl;
}
