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
	int count=0;
	int x;
	int y;
	int level;
	printf("Choisi le mode de difficulté entre: 1)Facile/ 2)Moyen/ 3)Difficile\n");
	scanf("%d", &level);
	switch(level)
        {
	case 1:
		printf("niveau facil\n");
		do
		{
			y=rand()% 100+1;
			printf("Entrez un numero de votre choix:\n");
			scanf("%d",&x);
			plus_moins(x,y);
			count++;
			if(count==1000)
				break;
		}
			while(x!=y);
	case 2:
		printf("niveau moyen\n");
                do
                {
                        y=rand()% 100+1;
                        printf("Entrez un numero de votre choix:\n");
                        scanf("%d",&x);
                        plus_moins(x,y);
                        count++;
                        if(count==25)
				printf("vous avez perdu");
                                break;
                }
                while(x!=y);


	case 3:
		printf("niveau difficile\n");
		do
		{
			y=rand()% 100+1;
			printf("Entrez un numero de votre choix:\n");
			scanf("%d",&x);
			plus_moins(x,y);
			count++;
			if(count==10)
				break;
		}
		while(x!=y);
	}
}
