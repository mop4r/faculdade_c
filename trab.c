#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define DIAS 5
#define BLOCOS 4
#define MAX 50

struct alunos {
	int matricula;
	char nome[100];
	char sobrenome[100];
	char email[50];
	int disciplinas[100];
	int gradehoraria[BLOCOS][DIAS];
};

struct disciplina {
	char codigo[10];
	char nome[50];
	char nomeprofessor[20];
	int cargahoraria;
	char horariosemanal[50];
};

void print_matriz(int gradehoraria[BLOCOS][DIAS]){
    int x, y;
    
    // linhas que sao os blocos
    for (x=0; x<BLOCOS; x++){
        printf("\n");
        // colunas que sao os dias
        for(y=0; y<DIAS; y++){
        	if(gradehoraria[x][y]==0){
            	printf("   -   ");
       		}
            if(gradehoraria[x][y]==1){
            	printf("  Algo ");
			}
			if(gradehoraria[x][y]==2){
            	printf("  Estr ");
			}
			if(gradehoraria[x][y]==3){
            	printf("  Sist ");
			}
			if(gradehoraria[x][y]==4){
            	printf("  Padr ");
			}
			if(gradehoraria[x][y]==5){
            	printf(" Banco ");
			}
			if(gradehoraria[x][y]==6){
            	printf(" 10:00   -   ");
			}
			if(gradehoraria[x][y]==7){
            	printf(" 13:00   -   ");
			}
			if(gradehoraria[x][y]==8){
            	printf(" 15:00   -   ");
			}
			if(gradehoraria[x][y]==9){
            	printf(" 08:00  Algo ");
			}
			if(gradehoraria[x][y]==10){
            	printf(" 08:00   -   ");
			}
        }
    }
}



int main(){
	
	int x,i,y;
	int j,c=0;
	char nome2[30], *t, *comp, *comp1;
	int matri=0, index, cont=0, cont1=0, contz=0, contp=0;
	int conty=0, contx=0;
	int escolha=1;
	char resp,resp1;
	
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
			 	

	struct alunos aluno[MAX];
	
	// zera a matriz para todos os alunos
	for(j=0;j<=MAX;j++){ 
		for (x=0; x<BLOCOS; x++){
	        for(y=0; y<DIAS; y++){
	        	aluno[j].gradehoraria[x][y]=0;
	        }
	    }
 	}

	while (escolha!=5)
	{	

		printf("\n ----------------------- ");
		printf("\n 1 - Cadastrar Aluno(s) ");
		printf("\n 2 - Cadastrar Materia(s) ");
		printf("\n 3 - Consultar Aluno(s) ");
		printf("\n 4 - Listar Disciplinas ");
		printf("\n 5 - Sair ");
		printf("\n ----------------------- ");
		printf("\n\n Escolha uma opcao: ");
		scanf("%d",&escolha);		
		
		switch (escolha) {
	
			case 1: 
			system("cls");
			
				for(j=0;j<=MAX;j++){
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
					int tam_string = sizeof(aluno[j].email);
					contz=0,contp=0,contx=0,conty=0,x=0;
					for(x=0;x<=tam_string;x++){
						if ('@' == aluno[j].email[x]) {
							contz++;
			         	    if (x < 3) {
			            		printf("\n Erro! Nao ha pelo menos 3 caracteres antes do @.\n\n");
			             		goto email;
			          		} 
			       		    else {
			        			for (y=x; y<=tam_string; y++){
			                		// Achou o ponto (.)
			                		if ('.' == aluno[j].email[y]) {
			                    		contp++;
			                    		// Verifica se ate chegar ao ponto (.) tinha no minimo 3 caracteres
			                			if (conty < 4) {
			                    		printf("\n Erro! Nao ha pelo menos 3 caracteres depois do @.\n\n");
			                    		goto email;
			                    		} 
									}
			                    conty++;
			                	}
			            	}
			        	}
   				 	}
   				 	if (contz==0) {
						printf("\n Erro! Email sem @.\n\n");
						goto email;
					}
					if (contp==0) {
			            printf("\n Erro! Email sem o ponto.\n\n");
						goto email;
			     	}
					c++;
					cdr:
					printf("\n Deseja cadastrar mais alunos? (s/n): ");
					scanf("%s",&resp);
						if(resp=='n'){
							system("cls");
							break;
					}
						if(resp!='n'&&resp!='s'){
							printf("\n Opcao Invalida!\n");
							goto cdr;
					}
				system("cls");
				}	
			break;
			
			case 2:
				if(c==0){
					system("cls");
					printf("\n Cadastre pelo menos um aluno antes.\n");
					break;
				}
				system("cls");
				matr:
				matri=0;
				printf("\n Entre com a matricula do aluno: ");
				scanf("%d",&matri);
				system("cls");
				index=-1;
				for(j=0;j<=c;j++){
					if(aluno[j].matricula==matri){
						index=j;
					}
				}
				if(index==-1){
					printf("\n Matricula nao encontrada.\n");
					goto matr;
				}
				// cadastra disciplina
				cadr:
				for(i=0;i<=2;i++){
					printf("\n Matricular Disciplinas (Codigos): ");
					scanf("%d",&aluno[index].disciplinas[i]);
					if(aluno[index].disciplinas[i]!=127 && aluno[index].disciplinas[i]!=122 && aluno[index].disciplinas[i]!=132 && aluno[index].disciplinas[i]!=135 && aluno[index].disciplinas[i]!=143){
						system("cls");
						printf("\n Codigo Invalido! Digite novamente.\n");
						goto cadr;
					}
					cadrmat:
					if(i<2){
<<<<<<< HEAD:trabfinal.c
					printf("\n Deseja cadastrar mais materias? (s/n): ");
					scanf("%s",&resp1);
					if(resp1=='n'){
						system("cls");
						break;
					}
					if(resp1!='n'&&resp1!='s'){
						printf("\n Opcao Invalida!\n");
						goto cadrmat;
					}
					}
					system("cls");
				}
				
			
				// checa os conflitos de horarios
					for(i=0;i<=2;i++){
						if(aluno[index].disciplinas[i]==127){
					  		for(i=0;i<=2;i++){
								if(aluno[index].disciplinas[i]==132){
				            		printf("\n Conflito de horarios! Cadastre novamente.\n");
				            		goto cadr;
				            	}
				         	}
				  		}
				         	
			         	if(aluno[index].disciplinas[i]==132){
				  		for(i=0;i<=2;i++){
							if(aluno[index].disciplinas[i]==127){
			            		printf("\n Conflito de horarios! Cadastre novamente.\n");
			            		goto cadr;
			            		}
			         		}
			    		}
			         	
			         	if(aluno[index].disciplinas[i]==143){
				  		for(i=0;i<=2;i++){
							if(aluno[index].disciplinas[i]==135){
			            		printf("\n Conflito de horarios! Cadastre novamente.\n");
			            		goto cadr;
			            		}
			         		}
			         	}
			         	
			         	if(aluno[index].disciplinas[i]==135){
				  		for(i=0;i<=2;i++){
							if(aluno[index].disciplinas[i]==143){
			            		printf("\n Conflito de horarios! Cadastre novamente.\n");
			            		goto cadr;
			          		  	}
			         		}
			         	}
				    }
				

					cont1=0;
					for(i=0;i<=2;i++){
						if(aluno[index].disciplinas[i]==122){
							cont1++;
			            	aluno[index].gradehoraria[0][0] = 9;
			            	aluno[index].gradehoraria[1][1] = 1;
			         	}
			         	if(aluno[index].disciplinas[i]==127){
			            	aluno[index].gradehoraria[2][1] = 2;
			            	aluno[index].gradehoraria[3][2] = 2;
			         	}
			         	if(aluno[index].disciplinas[i]==132){
			            	aluno[index].gradehoraria[2][1] = 3;
			            	aluno[index].gradehoraria[1][3] = 3;
			         	}
			         	if(aluno[index].disciplinas[i]==143){
			            	aluno[index].gradehoraria[1][4] = 4;
			         	}
			         	if(aluno[index].disciplinas[i]==135){
			            	aluno[index].gradehoraria[1][2] = 5;
			            	aluno[index].gradehoraria[1][4] = 5;
			         	}
			         	if(cont1==0){
			         		aluno[index].gradehoraria[0][0] = 10;
			         		aluno[index].gradehoraria[1][1] = 0;
			         	}
			        }
		        aluno[index].gradehoraria[1][0] = 6;
				aluno[index].gradehoraria[2][0] = 7;
				aluno[index].gradehoraria[3][0] = 8;	

			break;
			
			case 3:
				if(c==0){
					system("cls");
					printf("\n Cadastre pelo menos um aluno antes.\n");
					break;
				}
				system("cls");
				name:
				printf("\n Digite o nome do aluno, ou parte dele: ");
				fflush(stdin);
				fgets(nome2,30,stdin);
				for(j=0; j<=c; j++){
					t = strstr(aluno[j].nome,nome2);
					if (t!=NULL){
						printf("\n Nome: %s Sobrenome: %s Matricula: %d\n Email: %s", aluno[j].nome,aluno[j].sobrenome,aluno[j].matricula,aluno[j].email);
						printf(" Grade Horaria:\n\n        Seg    Ter    Qua    Qui    Sex");
						print_matriz(aluno[j].gradehoraria);
						printf("\n");
						cont++;
					}	
				}
				
				if(cont==0){
					system("cls");
					printf("\n Nome nao encontrado.\n");
					goto name;
				}
				cont=0;
				
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
			}
		}
	}
		system("pause");
		return 0;
}
=======
					printf("\n Deseja cadastrar mais materias? (s/n): ");
					scanf("%s",&resp1);
					if(resp1=='n'){
						system("cls");
						break;
					}
					if(resp1!='n'&&resp1!='s'){
						printf("\n Opcao Invalida!\n");
						goto cadrmat;
					}
					}
					system("cls");
				}
				
			
				// checa os conflitos de horarios
					for(i=0;i<=2;i++){
						if(aluno[index].disciplinas[i]==127){
					  		for(i=0;i<=2;i++){
								if(aluno[index].disciplinas[i]==132){
				            		printf("\n Conflito de horarios! Cadastre novamente.\n");
				            		goto cadr;
				            	}
				         	}
				  		}
				         	
			         	if(aluno[index].disciplinas[i]==132){
				  		for(i=0;i<=2;i++){
							if(aluno[index].disciplinas[i]==127){
			            		printf("\n Conflito de horarios! Cadastre novamente.\n");
			            		goto cadr;
			            		}
			         		}
			    		}
			         	
			         	if(aluno[index].disciplinas[i]==143){
				  		for(i=0;i<=2;i++){
							if(aluno[index].disciplinas[i]==135){
			            		printf("\n Conflito de horarios! Cadastre novamente.\n");
			            		goto cadr;
			            		}
			         		}
			         	}
			         	
			         	if(aluno[index].disciplinas[i]==135){
				  		for(i=0;i<=2;i++){
							if(aluno[index].disciplinas[i]==143){
			            		printf("\n Conflito de horarios! Cadastre novamente.\n");
			            		goto cadr;
			          		  	}
			         		}
			         	}
				    }
				

					cont1=0;
					for(i=0;i<=2;i++){
						if(aluno[index].disciplinas[i]==122){
							cont1++;
			            	aluno[index].gradehoraria[0][0] = 9;
			            	aluno[index].gradehoraria[1][1] = 1;
			         	}
			         	if(aluno[index].disciplinas[i]==127){
			            	aluno[index].gradehoraria[2][1] = 2;
			            	aluno[index].gradehoraria[3][2] = 2;
			         	}
			         	if(aluno[index].disciplinas[i]==132){
			            	aluno[index].gradehoraria[2][1] = 3;
			            	aluno[index].gradehoraria[1][3] = 3;
			         	}
			         	if(aluno[index].disciplinas[i]==143){
			            	aluno[index].gradehoraria[1][4] = 4;
			         	}
			         	if(aluno[index].disciplinas[i]==135){
			            	aluno[index].gradehoraria[1][2] = 5;
			            	aluno[index].gradehoraria[1][4] = 5;
			         	}
			         	if(cont1==0){
			         		aluno[index].gradehoraria[0][0] = 10;
			         		aluno[index].gradehoraria[1][1] = 0;
			         	}
			        }
		        aluno[index].gradehoraria[1][0] = 6;
				aluno[index].gradehoraria[2][0] = 7;
				aluno[index].gradehoraria[3][0] = 8;	

			break;
			
			case 3:
				if(c==0){
					system("cls");
					printf("\n Cadastre pelo menos um aluno antes.\n");
					break;
				}
				system("cls");
				name:
				printf("\n Digite o nome do aluno, ou parte dele: ");
				fflush(stdin);
				fgets(nome2,30,stdin);
				for(j=0; j<=c; j++){
					t = strstr(aluno[j].nome,nome2);
					if (t!=NULL){
						printf("\n Nome: %s Sobrenome: %s Matricula: %d\n Email: %s", aluno[j].nome,aluno[j].sobrenome,aluno[j].matricula,aluno[j].email);
						printf(" Grade Horaria:\n\n        Seg    Ter    Qua    Qui    Sex");
						print_matriz(aluno[j].gradehoraria);
						printf("\n");
						cont++;
					}	
				}
				
				if(cont==0){
					system("cls");
					printf("\n Nome nao encontrado.\n");
					goto name;
				}
				cont=0;
				
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
			}
		}
	}
		system("pause");
		return 0;
}
>>>>>>> dfd26f24d67fb56ec03fe7010341e964eb847a1b:trab.c
