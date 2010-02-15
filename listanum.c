/*
 * =====================================================================================
 *
 *       Filename:  listanum.c
 *
 *    Description: Crie um programa que leia uma sequência de números da entrada padrão,
 *    crie uma lista ligada com os números, *sem repetição* e depois escreva
 *    na saída padrão os números.
 *
 *
 *        Version:  1.0
 *        Created:  25-05-2009 23:39:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anderson de França Queiroz (A.F.Q), anderson.f.queiroz(.AT,)gmail dot com
 *        Company:  UFABC
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
	int n;
	struct Lista *nextlista;
}Lista;

Lista *novalista, *primeira, *atual, *busca;

int i;


void CriaLista()
{
	int num, sai;


	do
	{		
		novalista = (Lista *)malloc(sizeof(Lista)); // Aloca Nova Struct Lista

		if(primeira == (Lista *)NULL)
		{
			primeira = atual = novalista;
		}
		else
		{
			atual = primeira; // Vai para o início da lista
			
			while ( atual->nextlista != (Lista *)NULL)
			{
				atual = atual->nextlista; // Procura Fim da lista, ou seja, uma estrutura vazia...
			}
			atual->nextlista = novalista;
			atual = novalista;
			atual->nextlista = (Lista *)NULL;
		}
	
		VERIFICA:

		printf("Digite o %dº número: ", i);
		scanf("%d", &num);
		
			if (atual != primeira)
		{
			
			busca = primeira;
			
			do
			{
				

				if (busca->n == num)
				{
					printf("Esse número já existe! Digite outro\n ");
					goto VERIFICA;
				}
				busca =  busca->nextlista;
			}while(busca->nextlista != (Lista *)NULL);
		}
	
		atual->n = num;
		i++;
		
		printf("Deseja inserir um novo número? [1]Sim [2]Não ");
		scanf("%d", &sai);
	}while (sai != 2);
}

void EscreveLista()
{
	printf("\n");

	if (primeira == (Lista *)NULL)
	{
		printf("Lista Vazia!");
		return;
	}

	atual = primeira; // Vai para o início da Lista...

	do
	{
		printf("%d ", atual->n);
		
		atual = atual->nextlista;
	}while (atual != NULL);

	printf("\n\n");

}

int main()
{
	i = 1;
	primeira = (Lista *) NULL; // Sem dados

	CriaLista();
	EscreveLista();

return 0;

}
