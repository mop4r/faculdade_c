#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct habitantes {
	int idade, salario;
	char sexo;
};

int main(){
	
	int c;
	int escolha=1, cont=0, menoridade, maioridade, maior, menor, mulheres=0, mediasalario=0, somasalario=0;
	char resp;
	struct habitantes habitante[100];
	
		while(escolha!=3)
		{
			
			printf("\n ----------------------- ");
			printf("\n 1 - Cadastrar Habitantes (Minimo 2)");
			printf("\n 2 - Informacoes ");
			printf("\n 3 - Sair ");
			printf("\n ----------------------- ");
			printf("\n\n Escolha uma opcao: ");
			scanf("%d",&escolha);
		
			switch(escolha){
	
			case 1: 
			system("cls");
			
				for(c=0;c<=100;c++)
					{
				fflush(stdin);
				printf("\n Sexo do habitante (f para feminino \\ m para masculino): ");
				scanf("%s",&habitante[c].sexo);
				fflush(stdin);
				printf(" Idade do habitante: ");
				scanf("%d", &habitante[c].idade);
				fflush(stdin);
				printf(" Salario do habitante: ");
				scanf("%d", &habitante[c].salario);
				fflush(stdin);
				printf("\n Deseja cadastrar mais habitantes? (sim/nao): ");
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
				maior = habitante[0].idade;
				maioridade=0;
				menor = habitante[0].idade;
				menoridade=0;
				for(c=0;c<=cont;c++){
					
					
					if (habitante[c].idade>maior){
						maior=habitante[c].idade;
						maioridade=c;
					}
					
					if (habitante[c].idade<menor){
						menor=habitante[c].idade;
						menoridade=c;
					}					
				
					if(habitante[c].sexo=='f' && habitante[c].salario<=100)
					{
						mulheres++;
					}
					
					somasalario+=habitante[c].salario;
					
			}
					
					mediasalario=somasalario/(cont+1);
			
				printf("\nA maior idade eh: %d.\n",habitante[maioridade].idade);
				printf("\nA menor idade eh: %d.\n",habitante[menoridade].idade);
				printf("\nA media salarial eh: %d.\n",mediasalario);
				printf("\nA quantidade de mulheres com o salario ate R$100,00 eh %d.\n", mulheres);
			
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
