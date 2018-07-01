#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct alunos{
	float nota1,nota2,nota3,media;
	int presencas,matricula;
};

int main(){
	int c=0,escolha=0,reprovados=0,repfreq=0,percent,percent1,menornota,maiornota;
	float maior,menor;
	
	struct alunos aluno[10];
	
	while(escolha!=3){
		printf("\n ---------------------");
		printf("\n 1 - Cadastrar alunos. ");
		printf("\n 2 - Observar Dados. ");
		printf("\n 3 - Sair. ");
		printf("\n ---------------------");
		printf("\n Escolha uma das opcoes: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				system("cls");
				for(c=0;c<=9;c++){
				fflush(stdin);
				printf("\n Digite a matricula do aluno: ");
				scanf("%d",&aluno[c].matricula);
				fflush(stdin);
				printf(" Informe a primeira nota: ");
				scanf("%f",&aluno[c].nota1);
				fflush(stdin);
				printf(" Informe a segunda nota: ");
				scanf("%f",&aluno[c].nota2);
				fflush(stdin);
				printf(" Informe a terceira nota: ");
				scanf("%f",&aluno[c].nota3);
				fflush(stdin);
				printf(" Informe o numero de presencas: ");
				scanf("%d",&aluno[c].presencas);
				aluno[c].media=(aluno[c].nota1+aluno[c].nota2+aluno[c].nota3)/3;
				}
			system("cls");
			break;
			
			case 2:
				system("cls");
				maior=aluno[0].media;
				maiornota=0;
				menor=aluno[0].media;
				menornota=0;
				for(c=0;c<=9;c++){
					if(aluno[c].media>=6 && aluno[c].presencas>=40){
						printf("\n\n Matricula: %d \n Nota final: %.2f \n Presencas: %d \n Resultado: Aprovado. ",aluno[c].matricula, aluno[c].media, aluno[c].presencas);
					}
					if(aluno[c].presencas<40 || aluno[c].media<6){
						printf("\n\n Matricula: %d \n Nota final: %.2f \n Presencas: %d \n Resultado: Reprovado. ",aluno[c].matricula, aluno[c].media, aluno[c].presencas);
						reprovados++;
					}
					if(aluno[c].presencas<40){
						repfreq++;
					}
					if(aluno[c].media>maior){
						maior=aluno[c].media;
						maiornota=c;
					}
					if(aluno[c].media<menor){
						menor=aluno[c].media;
						menornota=c;
					}
				}
				
				percent=(100*repfreq)/10;
				percent1=(100*repfreq)/reprovados;
				
				printf("\n\n O total de alunos reprovados foi de %d.", reprovados);
				printf("\n A porcentagem de alunos reprovados por frequencia foi de: %d%% em relacao a todos os alunos, e de %d%% em relacao a todos reprovados.",percent,percent1);
				printf("\n A maior nota foi de: %.2f, a menor nota foi de %.2f.\n\n",aluno[maiornota].media,aluno[menornota].media);
			
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
