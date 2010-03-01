/*
 * =====================================================================================
 *
 *       Filename:  PilhaSeq.h
 *
 *    Description:  Biblioteca para pilha sequêncial
 *
 *        Version:  1.0
 *        Created:  24-02-2010 12:08:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#define TIPO template <typename Tipo>
#define PS PilhaSeq<Tipo>::

#include <stdexcept>

using std::logic_error;

namespace ED{

TIPO
class PilhaSeq 
{
	public:
		PilhaSeq(int size);
		~PilhaSeq();

		//Métodos Principais
		//
		void empilha(Tipo el)	throw (logic_error);
		Tipo desempilha()	throw (logic_error);

		//Métodos Auxiliáres
		//
		bool cheia();
		bool vazia();
		int tamanho();

	private:
		Tipo *vetor;
		int topo, size;
};


//==================Construtor
TIPO
PilhaSeq<Tipo>::PilhaSeq(int size)
{
	this->size = size;
	vetor = new Tipo[size];
	topo = -1;
}

//====================Destrutor
TIPO
PilhaSeq<Tipo>::~PilhaSeq()
{
	delete [] vetor;
}

//=====================Empilha
TIPO
void PilhaSeq<Tipo>::empilha(Tipo el)	throw (logic_error)
{
	if (topo == size-1)
		throw logic_error("Pilha Cheia!");

	vetor[++topo] = el;
}

//=====================Desempilha
TIPO
Tipo PS desempilha()	throw (logic_error)
{
	if (vazia())
		throw logic_error("Pilha Vazia!");
	return vetor[topo--];
}

//======================cheia
TIPO
bool PS cheia()
{
	return (topo == size -1);
}

//========================vazia
TIPO
bool PS vazia()
{
	return (topo < 0);
}

//======================tamanho
TIPO
int PS tamanho()
{
	return (topo + 1);
}

}
