/*
 * =====================================================================================
 *
 *       Filename:  FilaSeq.h
 *
 *    Description:  Biblioteca para Fila Sequencial
 *
 *        Version:  1.0
 *        Created:  24-02-2010 20:00:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#define TIPO template <typename Tipo>
#define FS FilaSeq<Tipo>::

#include <stdexcept>

using std::logic_error;

namespace ED{

TIPO
class FilaSeq
{
	public:
		FilaSeq(int size);
		~FilaSeq();

		//Métodos Principais
		//
		void insere(Tipo el)	throw (logic_error);
		Tipo retira()		throw (logic_error);

		//Métodos Auxiliares
		//
		bool cheia();
		bool vazia();
		int tamanho();

	private:
		Tipo *vetor;
		int ini, fim, nel, size;
};

//==================================Construtor
TIPO
FS FilaSeq(int size)
{
	this->size = size;

	vetor = new Tipo[size];

	fim = -1;
	ini = nel = 0;
}

//=====================================Destrutor
TIPO
FS ~FilaSeq()
{
	delete [] vetor;
}

//============================================Insere
TIPO
void FS insere(Tipo el)	throw (logic_error)
{
	if (nel == size)
		throw logic_error ("Fila cheia! T.T");

	fim++;
	if (fim >= size)
		fim = 0;

	vetor[fim] = el;
	nel++;
}

//===========================================retira
TIPO
Tipo FS retira()	throw (logic_error)
{
	if (fim < 0)
		throw logic_error ("Fila Vazia ¬¬ !");

	Tipo r = vetor[ini];

	ini++;
	if (ini >= size)
		ini = 0;

	nel--;

	return r;
}

//================================================cheia
TIPO
bool FS cheia()
{
	return (nel == size);
}

//==================================================vazia
TIPO
bool FS vazia()
{
	return (nel == 0);
}

//=================================================tamanho
TIPO
int FS tamanho()
{
	return nel;
}

}
