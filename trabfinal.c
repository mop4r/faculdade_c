#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct alunos {
	int matricula;
	char nome[100];
	char sobrenome[100];
	char email[50];
	int disciplinas[100];
	int gradehoraria[3][4];
};

struct disciplina {
	char codigo[10];
	char nome[50];
	char nomeprofessor[20];
	int cargahoraria;
	char horariosemanal[50];
};
char resp;

int main() 	{
	
	struct disciplina d1;
	strcpy(d1.codigo, "0122");
	strcpy(d1.nome, "Algoritmos");
	strcpy(d1.nomeprofessor, "Jonas");
	d1.cargahoraria=60;
	strcpy(d1.horariosemanal, "Segunda Bloco 1 e Terca Bloco 2");
	
	struct disciplina d2;
	strcpy(d2.codigo, "0127");
	strcpy(d2.nome, "Estrutura de Dados");
	strcpy(d2.nomeprofessor, "Rafael");
	d2.cargahoraria=60;
	strcpy(d2.horariosemanal, "Terca Bloco 3 e Quarta Bloco 4");
	
	struct disciplina d3;
	strcpy(d3.codigo, "0132");
	strcpy(d3.nome, "Sistemas Operacionais A");
	strcpy(d3.nomeprofessor, "Daniel");
	d3.cargahoraria=60;
	strcpy(d3.horariosemanal, "Terca Bloco 3 e Quinta Bloco 2");
	
	struct disciplina d4;
	strcpy(d4.codigo, "0143");
	strcpy(d4.nome, "Padroes de Projeto");
	strcpy(d4.nomeprofessor, "Eduardo");
	d4.cargahoraria=30;
	strcpy(d4.horariosemanal, "Sexta Bloco 2");
	
	struct disciplina d5;
	strcpy(d5.codigo, "0135");
	strcpy(d5.nome, "Banco de Dados II");
	strcpy(d5.nomeprofessor, "Pedro");
	d5.cargahoraria=60;
	strcpy(d5.horariosemanal, "Quarta Bloco 2 e Sexta Bloco 2");
	
	struct disciplina disciplinas[5];
	disciplinas[0]=d1;
	disciplinas[1]=d2;
	disciplinas[2]=d3;
	disciplinas[3]=d4;
	disciplinas[4]=d5;
			 	
	int x,i;

	int j,c;
	char nome2[30], *t, *comp, *comp1;
	struct alunos aluno[j];
	

	int matri, index, cont=0;
	int escolha=1;
	while (escolha!=5)
	{	
	
		printf("\n ----------------------- ");
		
		printf("\n 1 - Cadastrar Aluno ");
		printf("\n 2 - Consultar Aluno ");
		printf("\n 3 - Cadastrar Materia ");
		printf("\n 4 - Listar Disciplinas ");
		printf("\n 5 - Sair ");
		printf("\n\n Escolha uma opcao: ");
		scanf("%d",&escolha);		
		
		switch (escolha) {
	
			case 1: 
			system("cls");
			
				for(j=0;j<=50;j++){
				fflush(stdin);
				printf("\n Matricula: ");
				scanf("%d", &aluno[j].matricula);
				fflush(stdin);
				printf(" Nome: ");
				fgets(aluno[j].nome,100,stdin);
				printf(" Sobrenome: ");
				fgets(aluno[j].sobrenome,100,stdin);
				email:
				printf(" Email: ");
				fgets(aluno[j].email,50,stdin);
				comp=strstr(aluno[j].email,"@");
				comp1=strstr(aluno[j].email,".");
				if(comp==NULL){
					printf("\n Erro! Email sem @.\n\n");
					goto email;
				}
				if(comp1==NULL){
					printf("\n Erro! Email sem o ponto.\n\n");
					goto email;
				}
				printf("\n Deseja cadastrar mais alunos? (S/N): ");
				scanf("%s",&resp);
				
					if(resp=='n'){
						system("cls");
					break;
				}
					if(resp!='n'&&resp!='s'){
						printf("\n Opcao Invalida!\n");
					break;
				}
				c++;
				system("cls");
				
	}	
			break;
			
			case 2:
				system("cls");
				printf("\n Entre com o nome do aluno, ou parte dele: ");
				fflush(stdin);
				gets(nome2);
				for(j=0; j<=c; j++){
					t = strstr(aluno[j].nome,nome2);
					if (t!=NULL){
						printf("\n Nome: %s Sobrenome: %s Matricula: %d\n Email: %s Disciplinas Matriculadas (Codigos): 0%d, 0%d, 0%d\n", aluno[j].nome,aluno[j].sobrenome,aluno[j].matricula,aluno[j].email,aluno[j].disciplinas[0],aluno[j].disciplinas[1],aluno[j].disciplinas[2]);
						cont++;
					}
				}
					if(cont==0){
						printf("\n Nao encontrado.\n");
					}
					cont=0;
				
			break;
				
			case 3:
				system("cls");
				printf(" Entre com a matricula do aluno: ");
				scanf("%d",&matri);
				
				for(j=0;j<=c;j++){
						if(aluno[j].matricula==matri)index=j;
					}
					
				int i;
				
				for(i=0;i<=2;i++){
					printf(" Disciplinas Matriculadas (Codigos): ");
					scanf("%d",&aluno[index].disciplinas[i]);
				}
			system("cls");
			break;
			
			case 4:
				system("cls");
			 	for(x=0;x<5;x++){
				printf("\n Nome: %s\n Nome do Professor: %s\n Codigo: %s\n Carga Horaria: %d\n Horario Semanal: %s\n", disciplinas[x].nome,disciplinas[x].nomeprofessor,disciplinas[x].codigo,disciplinas[x].cargahoraria,disciplinas[x].horariosemanal);
				}
			
				break;
				
			
			if(escolha==5){	
			system("cls");
				printf("\n\n O Programa foi fechado");
				getch(); 
			}
		}
		}
			system("pause");
		return 0;
	}
