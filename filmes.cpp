#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
int i,num;
float mpreco,somapreco=0;
float mapreco,nmapreco;

struct jogos
{
   char nome[100];
}j[4];
void menu()
{
	printf(" %c", (char)201);
	for(i=1;i<=50;i++)
	{
		printf("%c",(char)205);
	}
	printf("%c",(char)187);
	printf(" \n %c\t\tMENU DOS FILMES\t\t\t    %c\n",(char)186,(char)186);
	printf(" %c", (char)204);
	for(i=1;i<=50;i++)
	{
		printf("%c",(char)205);
	}
	printf("%c",(char)185);
	printf(" \n %c\t\t1 - Visualizar Lista de filmes	    %c \n",(char)186,(char)186);
	printf(" %c", (char)204);
	for(i=1;i<=50;i++)
	{
		printf("%c",(char)205);
	}
	printf("%c",(char)185);
	printf(" \n %c\t\t2 - Procurar o Filme pretendido\t    %c \n",(char)186,(char)186);
	printf(" %c", (char)204);
	for(i=1;i<=50;i++)
	{
		printf("%c",(char)205);
	}
	printf("%c",(char)185);
	printf(" \n %c\t\t3 - Insira o Filme pretendido\t    %c \n",(char)186,(char)186);
	printf(" %c", (char)204);
	for(i=1;i<=50;i++)
	{
		printf("%c",(char)205);
	}
	printf("%c",(char)185);
	printf(" \n %c\t\t4 - Para Sair \t	   	    %c \n",(char)186,(char)186);
	printf(" %c", (char)200);
	for(i=1;i<=50;i++)
	{
		printf("%c",(char)205);
	}
	printf("%c",(char)188);
}

void insert()
{
	int i;
	printf("Insira quantos Filmes quer Inserir: ");
	scanf("%d",&num);
	fp=fopen("movies.txt", "a");
	struct jogos j[num];
	for(i=0;i<num;i++)
    {
        fflush(stdin);
        printf("Escreva o nome do Filme: ");
        gets(j[i].nome);
        fflush(stdin);
		fwrite(&j[i],sizeof(jogos),1,fp);
		printf("\n");
    }	
	fclose(fp);
}
void lista()
{
	fp=fopen("movies.txt", "r");
	for(i=0;i<=num;i++)
	{
		while(fread(&j[i],sizeof(jogos),1,fp)>0)
		{
	    printf("Nome do Filme: %s\n",j[i].nome);
		}
	}
	fclose(fp);
}
void search()
{
	int exist,nexist;
	char proc[50];
	fflush(stdin);
	printf("Indique-nos que Filme pretende: ");
	gets(proc);
	fflush(stdin);
	exist=0;
	nexist=0;
	for(i=0;i<num;i++)
	{
		if(strcmp(proc,j[i].nome)==0)
		{
		exist=1;
	    printf("Nome do Filme: %s",j[i].nome); 
        printf("\n");
		}
		else
		{
			if(exist==0)
			{
				nexist=nexist+1;
			}
		}
		if(nexist==num)
		{
			printf("\nAlgo de errado nao esta certo :p");
			printf("Try another thing :)");
		}
	}
}

main()
{
	int op;
  	struct jogos j;
	do
	{
	fp=fopen("movies.txt", "r");
	if (fp==NULL)
	{
		printf("\nImpossivel abrir o ficheiro!\n\n");
		fp=fopen("movies.txt", "a");
		insert();
		fclose(fp);
	}
	else
	{
		fp=fopen("movies.txt", "r");
		menu();
		printf("\n\nOpcoes: ");
		scanf("%d", &op);
	if(op<1 or op>5)
		{
		printf ("Opcao Invalida!\n\n");
		system("pause");
		system("cls");
		main();
		}
	}
		switch(op)
		{
		case 1:
			lista();
			system("pause");
			system("cls");
			main();
			break;
		case 2:
			search();
			system("pause");
			system("cls");
			main();
			break;
		case 3:
			insert();
			system("pause");
			system("cls");
			main();
			break;
		case 4:
			printf("CYA");
			exit(0);
		}	
	fclose(fp);	
	}
	while(op>=1 and op<=3 and op!=4);
}
