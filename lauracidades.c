#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct cidades {
	int codigo;
	int veiculos;
	int acidentes;
	char estado[100];
	char nome[100];
};

int main(){
	
	int c;
	int cont=0, cont1=0, menor, maior, escolha=1, nomemaior, nomemenor, soma=0, soma1=0, media=0, media1=0;
	char resp, *comp;
	struct cidades cidade[200];
	
		while(escolha!=3){
			printf("\n ----------------------- ");
		
			printf("\n 1 - Cadastrar Cidades (Minimo 2)");
			printf("\n 2 - Informacoes");
			printf("\n 3 - Sair ");
			printf("\n\n Escolha uma opcao: ");
			scanf("%d",&escolha);
		
			switch (escolha) {
	
			case 1: 
			system("cls");
			
				for(c=0;c<=200;c++){
				fflush(stdin);
				printf("\n Nome da cidade: ");
				fgets(cidade[c].nome,100,stdin);
				fflush(stdin);
				printf(" Codigo da cidade: ");
				scanf("%d", &cidade[c].codigo);
				fflush(stdin);
				printf(" Estado (Sigla): ");
				fgets(cidade[c].estado,100,stdin);
				fflush(stdin);
				printf(" Numero de veiculos de passeio: ");
				scanf("%d", &cidade[c].veiculos);
				printf(" Numero de acidentes fatais: ");
				scanf("%d", &cidade[c].acidentes);
				printf("\n Deseja cadastrar mais cidades? (S/N): ");
				scanf("%s",&resp);
					if(resp=='n'){
						system("cls");
					break;
				}
					if(resp!='n'&&resp!='s'){
						printf("\n Opcao Invalida!\n");
					break;
				}
				cont++;
				system("cls");
	}	
	
			break;
		
			case 2:
				system("cls");
				maior = cidade[0].acidentes;
				nomemaior=0;
				menor = cidade[0].acidentes;
				nomemenor=0;
				for(c=0;c<=cont;c++){
						if (cidade[c].acidentes>maior){
						maior=cidade[c].acidentes;
						nomemaior=c;
					}
					
					if (cidade[c].acidentes<menor){
						menor=cidade[c].acidentes;
						nomemenor=c;
					}
					
					soma+=cidade[c].veiculos;
					
					comp=strstr(cidade[c].estado,"rs");
					if(comp!=NULL){
						soma1+=cidade[c].acidentes;
						cont1++;
					}	
					comp=0;
				}
				
				media=soma/(cont+1);
				
				
				printf("\nO menor Indice de acidentes fatais no transito pertence a cidade de %s com um numero de %d acidentes.\n",cidade[nomemenor].nome, menor);
				printf("\nO maior Indice de acidentes fatais no transito pertence a cidade de %s com um numero de %d acidentes.\n",cidade[nomemaior].nome, maior);	
				printf("\nA media de veiculos nas cidades eh de %d, o total eh de %d.\n", media, soma);
				if(cont1>0){
				media1=soma1/cont1;
				printf("\nA media de acidentes fatais nas cidades do RS eh de %d, o total eh de %d.\n",media1, soma1);
				}
				
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
