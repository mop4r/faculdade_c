#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct clientes{
	int gasto;
	char nome[100];
};

int main(){
	int c;
	struct clientes cliente[16];
	
	for(c=1;c<=15;c++){
		fflush(stdin);
		printf("\n Iforme o nome do cliente: ");
		fgets(cliente[c].nome,100,stdin);
		fflush(stdin);
		printf(" Digite a quantidade de gasto: ");
		scanf("%d", &cliente[c].gasto);
	}
	
	for(c=1;c<=15;c++){
		if(cliente[c].gasto>1000){
			printf("\n Cliente %s gastou mais de 1000 reais.", cliente[c].nome);
		}
		if(cliente[c].gasto<1000){
			printf("\n Cliente %s gastou menos de 1000 reais.", cliente[c].nome);
			
		}
	}

	system("pause");
}
