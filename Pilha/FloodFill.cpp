/*
 * =====================================================================================
 *
 *       Filename:  FloodFill.cpp
 *
 *    Description: FloodFill lendo arquivo 
 *
 *        Version:  1.0
 *        Created:  28-02-2010 18:45:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q.), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  Universidade Federal do ABC - UFABC
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
#include <stdio.h>

#include "PilhaSeq.h"

using namespace std;

FILE *f;
char **mat;

void alocmat();

int main(int argc, char *argv[])
{
	char c;
/*
	if(argc != 2)
		cout << "\n\nUtilize a seguinte sintaxe: FloodFill nome_do_arquivo\n\n";
*/
	f = fopen("test", "rw");

	if(f == NULL)
	{
		cout << "O Aqquivo " << argv[1] << " não pode ser aberto\n\n";
		return(-1);
	}

	while( (c = fgetc(f)) != '\n')
	{
		cout << c;
		fflush(stdout);
	}
	
	alocmat();


}

void alocmat()
{
	int i = 0;
	char c;

	fclose(f);
	f = fopen("text", "rw");

	if ( f == NULL)
		cout << "merda\n";

	
	while( (c = fgetc(f)) != '\n')	
		i++;

	mat = new char*[i];
	for (int j = 0; j < i; j++)
		mat[j] = new char[i];

	fclose(f);
	f = fopen("text", "wr");

	for (int j = 0; j < i; j++)
	{
		c = fgetc(f);
		mat[0][j] = c;
		printf("%c", mat[0][j]);
		cout << c;
		fflush(stdout);
	}
}
