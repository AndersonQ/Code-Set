/*
 * =====================================================================================
 *
 *       Filename:  tempo.cpp
 *
 *    Description:  Implementação da classe de medir tempo.
 *
 *        Version:  1.0
 *        Created:  27-01-2009 18:14:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *        Company:  LCCV
 *
 * =====================================================================================
 */

/* #####   HEADER FILE INCLUDES   ################################################### */
#include "tempo.hpp"
#include <iostream>

/* #####   CLASS IMPLEMENTATIONS  -  EXPORTED CLASSES   ############################# */
using std::cout ;
using std::string ;

MedeTempo::MedeTempo( const string &in ) {
	mensagem = in ;
	inicio = clock();
}

MedeTempo::~MedeTempo(){
	inicio=clock()-inicio;
	cout << mensagem << " " << (double)( inicio/CLOCKS_PER_SEC ) << "s" << "\n" ;
}

