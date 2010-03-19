/*
 * =====================================================================================
 *
 *       Filename:  Calc.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26-02-2010 12:18:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <sstream>
#include "PilhaEnc.h"
#include "LibCalc.h"

using namespace std;
using ED::PilhaEnc;

PilhaEnc<float> *p; //Object Declaration

int main()
{

	string input;
	//stringstream sst; //For convet string in float

	cout << endl << "\tOlá, sou uma calculadora pós-fixa!" << endl;
	cout << endl << "Não sabe o que é notação pós-fixa? Google it ou http://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_polonesa_inversa" << endl<< endl;
	cout << endl << endl << "Reconheços os seguintes operadores:\n\n\t+ : Soma\n\t- : Subtração\n\t* : Multiplicação\n\t/ : Divisão" << endl << endl;
	cout << "Para finalizar a conte digite \"e\"" << endl << endl;
	cout << "Informe um número ou operador: ";
	
	while(input != "e")
	{
		cin >> input;
		escolhe(input);
	}
}
