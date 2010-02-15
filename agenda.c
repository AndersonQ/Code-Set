/*
 * =====================================================================================
 *
 *       Filename:  agenda.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31-05-2009 10:29:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  UFABC
 *
 * =====================================================================================
 */
#define _GNU_SOURCE
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct CP
{
	char *titulo;
	char *data;
	char *local;
	char *pessoa;
	char *descricao;
	struct CP *next;
}CP;

CP **comp;

int Getfile()
{
	FILE *arq;
	char *linha, *veri, *guarda;
	int i = 0, cont;
	size_t inutil = 10;

	arq = fopen("db.txt", "r");

	linha = (char *) malloc(1);

	if (!arq)
	{
		puts("O Arquivo não pode ser aberto");
		exit(0);
	}

	do
	{
		getline(&linha, &inutil, arq);
		veri = strstr(linha, "%TITULO");

		if (veri != NULL)
		{
			i++;
		}
	} while (*linha != '\n');


	fseek (arq, 0, SEEK_SET);

	comp = (CP **) calloc(i, sizeof(CP));

	
	for (cont = 0; cont < i; cont ++)
	{
		comp[cont] = (CP *) malloc(sizeof(CP));
	}

	cont = 0;

	//for (cont = 0; cont < i;)
	do
	{
		
		linha = (char *) malloc(sizeof(char)*60);
		getline(&linha, &inutil, arq);
		guarda = (char *) malloc(sizeof (linha));
		guarda = strstr(linha, "%TITULO");
		if (guarda != NULL)
		{
			comp[cont]->titulo = (char *) malloc(sizeof(linha));
			comp[cont]->titulo = guarda;
		}

		guarda = strstr(linha, "%DATA");
		if (guarda != NULL)
		{
			comp[cont]->data = (char *) malloc(sizeof(linha));
			comp[cont]->data = guarda;
		}

		guarda = strstr(linha, "%LOCAL");
		if (guarda != NULL)
		{
			comp[cont]->local = (char *) malloc(sizeof(linha));
			comp[cont]->local = guarda;
		}
		
		guarda = strstr(linha, "%PESSOA");
		if (guarda != NULL)
		{
			comp[cont]->pessoa = (char *) malloc(sizeof(linha));
			comp[cont]->pessoa = guarda;
		}
		
		guarda = strstr(linha, "%DESCRICAO");
                if (guarda != NULL)
		{
			comp[cont]->descricao = (char *) malloc(sizeof(linha));
			comp[cont]->descricao = guarda;
			cont ++;
		}

		guarda = strstr(linha, "%");
		if(guarda == NULL)
		{
			cont = cont - 1;
			strcat(comp[cont]->descricao, linha);
			cont = cont +1;
		}

	}while ( *linha != '\n');
	
	fclose(arq);
	/*
	cont = 0;
	
	
	
	for (cont = 0; cont < 3; cont ++)
	{
	
		puts(comp[cont]->titulo);
		puts(comp[cont]->data);
		puts(comp[cont]->local);
		puts(comp[cont]->pessoa);
		puts(comp[cont]->descricao);
	}*/

	return(i);
}

void Print_titulo(int ln)
{
	int i = 0;

	puts("Compromissos:\n");

	for (i = 0; i < ln; i++)
	{
		printf("%s", ++comp[i]->titulo);
		--comp[i]->titulo;
	}
}

void Mostra_data(int ln)
{
	int i = 0;
	char data [10], *veri;
	
	printf("\nEscolha uma data no foemato dd/mm/aaaa: ");
	scanf("%s", &data);
	
	for (i = 0; i < ln; i++)
	{
		veri = strstr(comp[i]->data, data);
		if (veri != NULL)
		{
			puts("\n");
			Print_comp(i);
		}
	}
	
}

void Mostra_pessoa(int ln)
{
	int i = 0;
	char pessoa [50], *veri;
	
	printf("\nEscolha o nome, ou parte, de uma pessoa: ");
	scanf("%s", &pessoa);
	
	for (i = 0; i < ln; i++)
	{
		veri = strstr(comp[i]->pessoa, pessoa);
		if (veri != NULL)
		{
			puts("\n");
			Print_comp(i);
		}
	}
	
}

int Print_comp(int i)
{
	puts(++comp[i]->titulo);
	--comp[i]->titulo;
	
	puts(++comp[i]->data);
	--comp[i]->data;
	
	puts(++comp[i]->local);
	--comp[i]->local;
	
	puts(++comp[i]->pessoa);
	--comp[i]->pessoa;
	
	puts(++comp[i]->descricao);
	--comp[i]->descricao;

	return(0);
}

void Menu(int ln)
{
	int i;
	
	do
	{
		printf("\nEscolha uma opção:\n");
		printf("\n[1] Lista Titulo dos compromissos\n[2] Lista compromissos de uma data a sua escolha\n[3] Listas os compromissos com uma pessoa a sua escolha\n[4] Sair\n\n");

		scanf("%d", &i);

		switch (i)
		{
			case 1:
				Print_titulo(ln);
				break;
			case 2:
				Mostra_data(ln);
				break;
			case 3:
				Mostra_pessoa(ln);
				break;
		}
	}while ( i != 4);
}

int main()
{
	int ln;

	ln = Getfile();
	Menu(ln);
	system("clear && cal");
	exit(1);
}
