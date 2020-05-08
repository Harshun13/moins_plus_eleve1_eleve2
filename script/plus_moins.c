#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void plus_moins(int choix, int total_pointp2)
{
	if(choix < total_pointp2)
	{
		printf("plus\n");
	}
	else if(choix > total_pointp2)
	{
		printf("moins\n");
	}
	else
	{
		printf("bingo\n");
	}
}
void POINTS(int count1, int count2)
{
	if(count1>count2)
	{	
		printf("vous avez gagné player1\n");
	}
	else if(count2>count1)
	{
		printf("vous avez gagné player2\n");
	}
	else if(count2==count1)
	{
		printf("Vous etes a egaliter\n");
	}
}

int main()
{
	int x, y, level ,choix;
	int total_pointp1=0;
	int total_pointp2=0;
	int points1,points2;
	int points_Player1=0;
	int points_Player2=0;
	int turn,i,tentative,choix_du_jouer,valeur,z;
	char player1[20];
	char player2[20];

	printf("Choisissez votre mode (1 ou 2)\n");
	printf("1) Mode Solo\n");
	printf("2) Mode Multi-Jouere\n");
	srand (time(NULL));
	y = rand()% 101;
	do
	{
		/*Choosing between solo or multiplayer which will be save in the variable choix*/
		printf("Votre choix : ");
		scanf("%d",&choix);
		if(choix!=1 && choix!=2)
		{
			printf("Erreur!! re-essayez svp\n");
		}
		else
		{
			break;
		}
	}
	while(choix!=1 && choix!=2);
	printf("\n");
	if (choix==1)
	{
		{
			printf("C'est le Mode Solo\n");
			printf("Choisi le mode de difficulté entre: 1)Facile/ 2)Moyen/ 3)Difficile\n");
			printf("Votre choix : ");
			scanf("%d",&level);

			if ((level>3) || (level<1))
			{
				printf("Erreur!! re-essayez svp\n");
				printf("\n");
			}
	
		}
		while(level > 3 || level < 1);
		switch(level)
		{
			case 1:
				level=1000;
				break;
			case 2:
				level=25;
				break;
			case 3:
				level=10;
				break;
		}	

		printf("\n");
		//variable pour compter les tentatives du jouer
		int temp=0;
		do
		{   
			printf("Inserer votre numero: ");
			scanf("%d",&x);
			//appel du function
			plus_moins(x,y); 
			if (x == y)
			{
				break;
			}

			temp+=1;

			if (temp==level)//This statement will run on the last try
			{
				printf("Malheureusement vos nombres d'essais sont arrives a terme!\n");
			}

		}
		while(temp != level);
	}

	else
	{
		
		printf("C'est le Mode Multi-Jouere\n");
		printf("Choisissez le nombre d'essaie\n");
		do
		{
			printf("Votre choix : ");
			scanf("%d",&turn);
			if (turn>20)
			{
				printf("Erreur trop de tour!!\n");
				printf("Re-essayez\n");
			}
		}
		while(turn>20);

		printf("\n");
		
		int count1=turn;
		int count2=turn;
		
		for(int i=1; i<turn; i++)
		{
			printf("Player1 choissisez le nombre de tentative pour Player2 (minimum 10) :");
			scanf("%d",&tentative);
			printf("Vous etes au tour numero %d \n",i);
			printf("\n");
			
			//player2
			srand (time(NULL));
			valeur = rand()% 101;
			
			for(int f=1;f<=tentative;f++)
			{
				printf("Player2 votre nombre d'essaie est %d\n ", f);
				printf("Inserez un numero : ");
				scanf("%d",&choix_du_jouer);
				count2--;
				plus_moins(choix_du_jouer,valeur);
				printf("\n");

				

				if(f==tentative)
				{
					printf("Player2 vous avez pas trouvez la reponse a temps!\n");
				}

				if (choix_du_jouer==valeur)
				{
					break;
				}
				
				

			}
			//player1
			printf("\n");
			printf("Maintenant c'est au tour de l'autre jouere\n");
			
			srand (time(NULL));
			valeur = rand()% 101;
			for(int z=1;z<=tentative;z++)
			{
				printf("Player1 Vous etes au tentative numero %d\n",z);
				printf("Entrez un numero : ");
				scanf("%d",&choix_du_jouer);
				count1--;
				plus_moins(choix_du_jouer,valeur);

				printf("\n");


				if(z==tentative)
				{
					printf("Player1 vous avez pas trouvez la reponse a temps! \n");
				}

				if (choix_du_jouer==valeur)
				{
					break;
				}
			
			}
			printf("Le score jouer 1 est: %d\n", count1);
			printf("Le score jouer 2 est: %d\n", count2);
			printf("\n");
			POINTS(count1,count2);		
			break;

		}
		
	}

}

