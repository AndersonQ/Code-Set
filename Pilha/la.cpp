/*
 * =====================================================================================
 *
 *       Filename:  la.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  28-02-2010 19:37:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <fstream>
#include <string>
#include <iostream>
//using std::fout;
using std::string;
using namespace std;
int main()
{
	string texto;
	ofstream arquivo("test");
	texto.assign("Curso C++");
	arquivo << texto;
	texto = "lala";
	arquivo >> texto;
	arquivo.close();
	return 0;
}

