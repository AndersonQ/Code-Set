/*
 * =====================================================================================
 *
 *       Filename:  EncFila.h
 *
 *    Description:  Library for Fila Encadeada
 *
 *
 *        Version:  1.0
 *        Created:  26-02-2010 10:15:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#define TIPO template <typename Tipo>
#define FE FilaEnc<Tipo>::

#include <stdexcept>

using std::logic_error;

namespace ED
{

	TIPO
	class FilaEnc
	{
		public:
			FilaEnc();
			~FilaEnc();

			//Main functions
			void insere(Tipo el)	throw (logic_error);
			Tipo retira()		throw (logic_error);

			//Auxiliary functions
			bool vazia();
			int tamanho();

		private:
			struct Celula
			{
				Tipo el;
				Celula *next;
			};

			Celula *home, *end;
			unsigned int nel;
	};

	//===========================Constructor
	TIPO
	FE FilaEnc()
	{
		home = end = new Celula;
		home->next = NULL;
		nel = 0;
	}

	//=========================Destructor
	TIPO
	FE ~FilaEnc()
	{
		Celula *tmp = home;
		while (end->next)
		{
			home = home->next;
			delete tmp;
			tmp = home;
		}
	}

	//==========================Insere
	TIPO
	void FE insere(Tipo el)	throw (logic_error)
	{
		end->next = new  Celula;

		if (!end->next)
			throw logic_error ("Not memory free! T.T");

		end = end->next;
		end->next = NULL;
		end->el = el;
		nel++;
	}

	//================================Retira
	TIPO
	Tipo FE retira()	throw (logic_error)
	{
		if (vazia())
			throw logic_error ("Empty row! ¬¬");

		Tipo tmp; 
		Celula *p;

		tmp = home->el;
		p = home;
		home = home->next;

		nel--;
		
		delete p;

		return tmp;
	}

	//==============================vazia
	TIPO
	bool FE vazia()
	{
		return (nel <= 0);
	}

	//================================tamanho
	TIPO
	int FE tamanho()
	{
		return nel;
	}

}
