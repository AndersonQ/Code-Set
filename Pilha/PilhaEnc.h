/*
 * =====================================================================================
 *
 *       Filename:  PilhaEnc.h
 *
 *    Description:  Biblioteca de Pilah Encadeada
 *
 *
 *        Version:  1.0
 *        Created:  24-02-2010 12:21:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#define TIPO template <typename Tipo>
#define PE PilhaEnc<Tipo>::

#include <stdexcept>

using std::logic_error;

namespace ED{

TIPO
class PilhaEnc
{
	public:
		PilhaEnc();
		~PilhaEnc();

		//Métodos Principais
		//
		void empilha(Tipo el)	throw (logic_error);
		Tipo desempilha()	throw (logic_error);

		//Métodos Auxiliares
		//
		bool vazia();
		int tamanho();

	private:
		struct Celula
		{
			Tipo el;
			Celula *prox;
		};

		Celula *topo;
		int nel;
};

//============================Construtor

TIPO
PE PilhaEnc()
{
	topo = NULL;
	nel = 0;
}

TIPO
PE ~PilhaEnc()
{
	Celula *tmp;
	while(topo)
	{
		tmp = topo;
		topo = topo->prox;
		delete tmp;
	}
}

//===========================================Empilha
TIPO
void PE empilha(Tipo el)	throw (logic_error)
{
	
	
	Celula *tmp = new Celula;

	if (tmp == NULL)
		throw logic_error("Memória esgotada! T.T");
	
	tmp->el = el;
	tmp->prox = topo;
	topo = tmp;
	
	nel++;
}

//=========================================Desempilha
TIPO
Tipo PE desempilha()	throw (logic_error)
{
	if (vazia())
		throw logic_error("Pilha Vazia! ¬¬");

	Tipo tmp = topo->el;
	Celula *ptr = topo;
	topo = topo->prox;
	nel--;
	
	delete ptr;
	
	return tmp;
}

//========================================vazia
TIPO
bool PE vazia()
{
	return (nel == 0);
}

//============================================tamanho
TIPO
int PE tamanho()
{
	return nel;
}

}

