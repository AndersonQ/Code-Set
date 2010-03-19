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

#include "PilhaEnc.h"

using namespace std;

FILE *f;
char **mat;

void alocmat();

int main(int argc, char *argv[])
{
	//char c;
/*
	if(argc != 2)
		cout << "\n\nUtilize a seguinte sintaxe: FloodFill nome_do_arquivo\n\n";
*/
	f = fopen("test", "r");

	if(f == NULL)
	{
		cout << "O Aqquivo " << argv[1] << " não pode ser aberto\n\n";
		return(-1);
	}

	/*while( (c = fgetc(f)) != '\n')
	{
		cout << c;
		fflush(stdout);
	}*/
	
	alocmat();


}

void alocmat()
{
	int r,c;
	char ch;

	r = c = 0;

	fclose(f);
	f = fopen("test", "r");

	if ( f == NULL)
	{
		cout << "merda\n";
		return ;
	}

	
	while( (ch = fgetc(f)) != EOF)
	{
		if (ch == '\n') r++;
		if (ch != '\n') c++;
	}

	c = c/r;

	mat = new char*[c];
	for (int i = 0; i < c; i++)
		mat[i] = new char[r];

	fclose(f);
	f = fopen("test", "r");

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			ch = fgetc(f);
			mat[i][j] = ch;
			printf("%c", mat[i][j]);
			fflush(stdout);
		}
	}

	puts("");

	for(int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			printf("%c", mat[i][j]);
			cout << mat[i][j];
		}
	fflush(stdout);

	printf("\n\n%c%c\n\n", mat[2][8], mat[2][9]);
	fflush(stdout);

	puts("");
}
