/*
 * =====================================================================================
 *
 *       Filename:  LibCalc.cpp
 *
 *    Description:  Code of functions declared in LibCalc.h
 *
 *
 *        Version:  1.0
 *        Created:  26-02-2010 18:38:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#define Mdesempila	float a,b; \
			try \
			{ \
			a = (float) p.desempilha(); \
			b = (float) p.desempilha(); \
			} \
			catch (logic_error)\
			{ \
			cout << "Favor inserir, no mínimo, mais um número" << endl; \
			cout << "Número restante na memória = ";\
			}

#include <string>
#include <sstream>
#include <iostream>

//===================================escolhe
void escolhe(string input)
{
	float num;

	stringstream sst;

	if (input == "+")
		sum();

	else if (input == "-")
		subtraction();

	else if (input == "*")
		multiplication();

	else if (input ==  "/")
		split(); 
	
	else
	{
		sst << input << endl;
		sst >> num;
		p.empilha(num);
	}
}

//=============================================sum
void sum()
{
	Mdesempila
	p.empilha(a + b);
	cout << a + b << endl;
}

//============================================subtraction
void subtraction()
{
	Mdesempila
	p.empilha (a - b);
	cout << a - b << endl;
}

//===========================================split
void split()
{
	Mdesempila
	p.empilha(a / b);
	cout << a / b << endl;
}

//===========================================multiplication
void multiplication()
{
	Mdesempila
	p.empilha(a * b);
	cout << a * b << endl;
}
