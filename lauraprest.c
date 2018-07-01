
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct prestacoes{
	float pagaV, pagaP, pagaPP;
	char meio;
};
int main()
{
	int c,escolha;
	char resp;
	float CV, CP, CPP, T;
	struct prestacoes prestacao[16];
	
		while(escolha!=3)
		{
		printf("\n ---------------------");
		printf("\n 1 - Cadastrar Transacoes. ");
		printf("\n 2 - Observar dados. ");
		printf("\n 3 - Sair. ");
		printf("\n ---------------------");
		printf("\n Escolha uma das opcoes: ");
		scanf("%d", &escolha);
		
		switch(escolha)
		{
			case 1:
				system("cls");
				for(c=1; c<=15; c++)
				{
					printf("\n Informe o tipo de transicao.");
					tipo:
					printf("\n\n V para a Vista e P para a Prazo: ");
					scanf("%s", &prestacao[c].meio);
					fflush(stdin);
					
					if(prestacao[c].meio=='v')
					{
						printf("\n Informe quanto pagou: ");
						scanf("%f", &prestacao[c].pagaV);
					}
					
					CV += prestacao[c].pagaV;
					
					if(prestacao[c].meio=='p')
					{
						printf("\n Existem tres parcelas de prestacoes, informe quanto pagara na primeira: ");
						scanf("%f", &prestacao[c].pagaP);
						
					CP += prestacao[c].pagaP;
							
						printf("\n Informe quanto pagara no total: ");
						scanf("%f", &prestacao[c].pagaPP);
						
					CPP += prestacao[c].pagaPP;
					
					}
					
					if(prestacao[c].meio!='v'&&prestacao[c].meio!='p')
					{
						printf("\n Opcao Invalida!\n");
					goto tipo;
					}
					
					pess:
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
					goto pess;
					}
						
					system("cls");
				}	
	
				break;
			
			case 2:
			T = CPP + CV;
			system("cls");
			printf("\n O valor total das compras a vista eh: %.2f", CV);
			printf("\n O valor total das compras a prazo eh: %.2f", CPP);
			printf("\n O valor total das compras efetuadas eh: %.2f", T);
			printf("\n O valor das primeiras prestacoes a prazo eh: %.2f\n", CP);
			
				break;
			
			if(escolha==3){	
			system("cls");
			getch(); 
			}	
		}
	}
}
