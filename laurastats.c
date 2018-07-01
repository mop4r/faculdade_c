
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct pessoas{
	float altura,peso;
	int idade;
};
int main()
{
	int c,escolha,mais50=0,dadu=0,pesu=0,cont=0,porcent; 
	float media,dadus;
	char resp;
	struct pessoas pessoa[26];
	
		while(escolha!=3)
		{
		printf("\n ---------------------");
		printf("\n 1 - Cadastrar Dados. ");
		printf("\n 2 - Observar Dados. ");
		printf("\n 3 - Sair. ");
		printf("\n ---------------------");
		printf("\n Escolha uma das opcoes: ");
		scanf("%d", &escolha);
		
		switch(escolha)
		{
			case 1:
				system("cls");
				for(c=0;c<=25;c++)
				{
					printf("\n Informe a idade: ");
					scanf("%d",&pessoa[c].idade);
					printf(" Informe a altura: ");
					scanf("%f",&pessoa[c].altura);
					printf(" Informe o peso: ");
					scanf("%f",&pessoa[c].peso);
					pess:
					printf("\n Deseja cadastrar mais? (sim/nao): ");
					scanf("%s",&resp);
					if(resp=='n')
					{
						system("cls");
						break;
					}
					if(resp!='n'&&resp!='s')
					{
						printf("\n Opcao Invalida!\n");
						goto pess;
					}
					cont++;
				}
	
				break;
			
			case 2:
				
			for(c=0;c<=cont;c++){
				if(pessoa[c].idade>=50)
					{
						mais50++;
					}
					if(pessoa[c].idade>=10 && pessoa[c].idade<=20)
					{
						dadu++;
					}
					if(pessoa[c].idade>=10 && pessoa[c].idade<=20)
					{
						dadus+=pessoa[c].altura;
					}
					if(pessoa[c].peso<=40)
					{
						pesu++;
					}
			}

			porcent=(100*pesu)/(cont+1);
			media=dadus/dadu;
			system("cls");
			printf("\n Quantidade de pessoas acima de 50: %d",mais50);
			printf("\n Media da altura entre pessoas com 10 e 20 anos: %.2f",media);
			printf("\n Percentagem de pessoas com peso inferior a 40 quilos entre todas: %d por cento.\n",porcent);

			break;
			
			if(escolha==3){	
			system("cls");
			getch();
			}	
		}
	}
	system("pause");
	return 0;
}
