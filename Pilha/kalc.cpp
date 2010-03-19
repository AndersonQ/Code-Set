#define Mdesempila	float a,b; \
			try \
			{ \
			b = (float) p.desempilha(); \
			a = (float) p.desempilha(); \
			} \
			catch (logic_error)\
			{ \
			cout << "Favor inserir, no mínimo, mais um número" << endl; \
			cout << "Número restante na memória = ";\
			}

#include <string>
#include <sstream>

#include <iostream>
//#include <string>
//#include <sstream>
#include "PilhaEnc.h"
//#include "LibCalc.h"

using namespace std;
using ED::PilhaEnc;

PilhaEnc<float> p; //Object Declaration

void escolhe(string input);
void sum();
void subtraction();
void split();
void multiplication();

int main()
{

	string input;
	//stringstream sst; //For convet string in float

	cout << endl << "\tOlá, sou uma calculadora pós-fixa!" << endl;
	cout << endl << "Não sabe o que é notação pós-fixa? Google it ou http://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_polonesa_inversa" << endl<< endl;
	cout << endl << endl << "Reconheços os seguintes operadores:\n\n\t+ : Soma\n\t- : Subtração\n\t* : Multiplicação\n\t/ : Divisão" << endl << endl;
	cout << "Para finalizar a conta digite \"exit\"" << endl << endl;
	cout << "Informe um número ou operador: ";
	
	while(input != "exit")
	{
		cin >> input;
		escolhe(input);
	}
}



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
	Mdesempila//Macro
	p.empilha(a + b);
	cout << a + b << endl;
}

//============================================subtraction
void subtraction()
{
	Mdesempila//Macro
	p.empilha (a - b);
	cout << a - b << endl;
}

//===========================================split
void split()
{
	Mdesempila//Macro
	p.empilha(a / b);
	cout << a / b << endl;
}

//===========================================multiplication
void multiplication()
{
	Mdesempila//Macro
	p.empilha(a * b);
	cout << a * b << endl;
}
