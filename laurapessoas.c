#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct pessoas{
	int idade;
	char cordocabelo[50];
	char cordosolhos[50];
	char sexo[10];
};

int main(){
	
	int c;
	int  escolha=1, cont=0, maior, idademaior, pessoar=0;
	char resp, *comp1, *comp, *comp2;
	
	struct pessoas pessoa[500];
		while(escolha!=3)
		{
			
			printf("\n ----------------------- ");
			printf("\n 1 - Cadastrar Pessoa (Minimo 2)");
			printf("\n 2 - Informacoes ");
			printf("\n 3 - Sair ");
			printf("\n ----------------------- ");
			printf("\n\n Escolha uma opcao: ");
			scanf("%d",&escolha);
		
			switch (escolha) {
	
			case 1: 
			system("cls");
			
				for(c=0;c<=500;c++)
					{
				fflush(stdin);
				printf(" Informe a Idade: ");
				scanf("%d", &pessoa[c].idade);
				fflush(stdin);
				printf(" Informe o Sexo: ");
				fgets(pessoa[c].sexo,10,stdin);
				fflush(stdin);
				printf(" Informe a Cor dos olhos: ");
				fgets(pessoa[c].cordosolhos,50,stdin);
				fflush(stdin);
				printf(" Informe a Cor do cabelo: ");
				fgets(pessoa[c].cordocabelo,50,stdin);
				fflush(stdin);
				printf("\n Deseja cadastrar mais pessoas? (sim/nao): ");
				scanf("%s",&resp);
					if(resp=='n')
					{
						system("cls");
					break;
					}
					if(resp!='n'&&resp!='s')
					{
						printf("\n Opcao Invalida!\n");
					break;
					}
				cont++;
				system("cls");
					}	
	
					break;
		
			case 2:
				system("cls");
				maior = pessoa[0].idade;
				idademaior=0;
				
				for(c=0;c<=cont;c++){	
					if (pessoa[c].idade>maior){
						maior=pessoa[c].idade;
						idademaior=c;
					}
					
				comp=strstr(pessoa[c].cordocabelo,"louro");
				comp1=strstr(pessoa[c].cordosolhos,"verde");
				comp2=strstr(pessoa[c].sexo,"f");
				
				if(comp1!=NULL && comp!=NULL && comp2!=NULL && pessoa[c].idade>17 && pessoa[c].idade<36)
				{
					pessoar++;
				}
				comp=0;
				comp1=0;
				comp2=0;
			}	
				printf("\nA maior idade do grupo eh: %d. \n",pessoa[idademaior].idade);
				printf("\nA quantidade de pessoas loiras, com olhos verdes, do sexo feminino entre 18 e 35 anos eh: %d.\n", pessoar);
			
			break;
				
			if(escolha==3){	
			system("cls");
				printf("\n\n O Programa foi fechado");
				getch();
			}
				
			}
		}
		system("pause");
		return 0;
}
