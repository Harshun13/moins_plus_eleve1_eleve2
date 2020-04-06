#include<stdio.h>
#include<stdlib.h>
void plus_moins(int choix, int valeur)
{
	if(choix < valeur)
	{
		printf("plus\n");
	}
	else if(choix > valeur)
	{
		printf("moins\n");
	}
	else
	{
		printf("bingo\n");
	}
}

int main()
{
	int x;
	int y;
	y = rand()%100 + 1;
	{
		do
		{
			printf("Entrez un numero de votre choix:\n");
			scanf("%d",&x);
			plus_moins(x,y);
		}
		while (x!=y);

	}
}

