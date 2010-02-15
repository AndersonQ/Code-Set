/* Programa: pergunta ao usuário um número N; em seguida lê duas matrizes NxN; depois, multiplica as duas. */
#include <stdio_ext.h>
#include <stdlib.h>


float **fazmatriz(int n)
{
	int i;
	float **m;

	m = (float **) calloc(n, sizeof(float*));

	for (i = 0; i < n; i++)
	{
		m[i] = (float *) calloc(n, sizeof(float *));

		if (m[i] == NULL)
		{
			printf("ERRO! Memória Insufucuente!");
			return (NULL);
		}
	}

	return (m);
}

float **liberamatriz(float **m, int n)
{

	int i;

	if (m == NULL)
	{
		return NULL;
	}

	for (i = 0; i < n; i++)
	{
		free(m[i]);
	}

	free(m);

	return (NULL);
}
		

float **multiplica (float **m1, float **m2, float **mr, int n)
{
	int i, l, c;

	for (l = 0; l < n; l++)
	{
		for (c = 0; c < n; c++)
		{
			for (i = 0; i < n; i++)
			{
				mr[l][c] += m1[l][i] * m2[i][c];
			}
		}
	}
getchar();
return (mr);

}

float **preenche(float **m, int n, int matriz)
{
	int l, c;
	float v;

	for (l = 0; l < n; l++)
	{
		for (c = 0; c < n; c++)
		{
				
			printf("Para a matriz %d, indique o valor de a[%d][%d]: ", matriz, (l + 1), (c + 1));
			scanf("%f", &v);
			m[l][c] = v;
		}
	}


return (m);

}

void imprime(float **m,int n, int matriz)
{
	int l, c;

	printf("\nMatriz %d\n", matriz);

	for (l = 0; l < n; l++)
	{
		for (c = 0; c < n; c++)
		{
			printf("a[%d][%d]: %.2f\n",(l + 1), (c + 1), m[l][c]);
		}
	}

	printf("\n");
}

main()
{


	int n, matriz, o;
	char c;
	float **m1, **m2, **mr;

	printf("\nDigite a ordem das Matrizes: ");
	scanf("%d", &n);
	printf("\n");

	if (n <= 0)
	{
		printf("\n\tERRO!\n\nA Matriz NÃO pode ter ordem 0!\n\n");
		printf("\nDigite uma ordem VÁLIDA para a Matriz: ");
		scanf("%d", &n);
	}

	o = n * n;

	do{
	if ( o >= 12)
	{
		printf("\nSuas matrizes terão %d elementos cada, totalizando %d elementos. Dará trabalho preenche-las; tens certeza que queres mante-las com ordem %d ? [s/n]", (n * n), (2 * (n * n)), n);

		scanf("%s", &c);
		if ( c == 'n' || c == 'N')
		{
			printf("\n\\o/ Votória da preguiça!\n\n");
			printf("Digite a nova ordem: ");
			scanf("%d", &n);
			printf("\n");
		}
		else
		{
			printf("\nTens certeza?? Vai dar trabalho digitar isso tudo... [s/n]");
			scanf("%s", &c);
			if ( c == 'n' || c == 'N')
			{
				printf("\n\\o/ Votória da preguiça!\n\n");
				printf("Digite a nova ordem: ");
				scanf("%d", &n);
				printf("\n");
			}
			else
			{
				printf("\nVocê vai ter tanto trabalho... mas se quiser desistir aperte \"Ctrl + c\"\n\n");
				break;
			}
		}
	}
	}while ( n >= 4);
	
	m1 = fazmatriz(n);
	m2 = fazmatriz(n);
	mr = fazmatriz(n);

	matriz = 1;
	preenche(m1, n, matriz);
	imprime(m1, n, matriz);


	matriz = 2;
	preenche(m2, n, matriz);
	imprime(mr, n, matriz);

	mr = multiplica(m1, m2, mr, n);
	matriz = 3;
	imprime(mr, n, matriz);

	m1 = liberamatriz(m1, n);
	m2 = liberamatriz(m2, n);
	mr = liberamatriz(mr, n);

	return 0;
}

