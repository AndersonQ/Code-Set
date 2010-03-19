/*
 * =====================================================================================
 *
 *       Filename:  Eq.cpp
 *
 *    Description:  Validador  de expressão aritimética
 *
 *
 *        Version:  1.0
 *        Created:  27-02-2010 12:19:16
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
#include "PilhaEnc.h"

using namespace std;
using ED::PilhaEnc;

string valida(string exp);

int main()
{
	string exp, ok = "Certa!";

	cout << "\n\nPara sair utilize \"exit\"\nInforme uma expressão para ser validada: ";

	ok = "Certa!";
	while (exp != "exit" && ok != "Errada!")
	{
		cin >> exp;
		ok = valida(exp);
	}

	if (ok != "Errada!")
		ok = "Certa!";
		
	cout <<"\n\nA Expressão está " << ok << "\n\n";

}

string valida(string exp)
{
	static PilhaEnc<string> p;

	string ok, a = "";

	if (exp == "(" || exp == "[" || exp == "{")
		p.empilha(exp);

	if ( exp == ")")
	{
		try
		{
			a = p.desempilha();
		}
		catch (logic_error)
		{
			ok = "Errada!";
		}

		if ( a != "(")
			ok = "Errada!";
	}

	if ( exp == "]")
	{
		try
		{
			a = p.desempilha();
		}
		catch (logic_error)
		{
			ok = "Errada!";
		}

		if ( a != "[")
			ok = "Errada!";
	}

	if (exp == "}")
	{
		try
		{
			a = p.desempilha();
		}
		catch (logic_error)
		{
			ok = "Errada!";
		}

		if ( a != "{")
			ok = "Errada!";
	}

	return ok;
}
