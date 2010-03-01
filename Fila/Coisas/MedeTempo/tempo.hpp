/*
 * =====================================================================================
 *
 *       Filename:  tempo.hpp
 *
 *    Description:  Arquivo que implementa uma classe que conta o tempo.
 *
 *        Version:  1.0
 *        Created:  27-01-2009 17:47:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
#ifndef _TEMPO_HPP
#define _TEMPO_HPP

/* #####   HEADER FILE INCLUDES   ################################################### */
#include	<ctime>
#include	<string>

/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */
using std::string ;

/** 
* @brief Classe que mede o tempo. Começa a contar na inicialização e
* termina na destruição.
*/
class MedeTempo {
	private:
		string mensagem ;
		clock_t inicio ;
	public:
		
		/** 
		* @brief	Contrutor que aceita o nome da função testada.
		* 
		* @param &in	Nome da função que você vai testar.
		*/
		MedeTempo( const string &in ) ;

		~MedeTempo() ;
};

#endif	/* end _TEMPO_HPP */
