#include <stdio.h> /* para funcao printf*/
#include <fcntl.h> /* para funcao open()*/
#include <unistd.h> /* para funcao close()*/
#include <stdlib.h> /* para funcao exit()*/


int main(int argc, const char *argv[]){
	int fp; 
	int i ;
	char nome[50];
	char idade[50];

	printf("Digite o seu nome:");
	gets(nome);
	printf("Digite a sua idade:");
	gets(idade);
	
	//abre o arquivo. Se não colocar o S_IRWXU não tem acesso ao arquivo
	fp = open (nome, O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

	// Escreve caracterer por caracterer da string
	write(fp, "Nome: ", 6*sizeof(char)); 	
		for(i = 0 ; nome[i]; i++)
		{	
	 		write(fp, &(nome[i]), 1); 	
			
		}
	write(fp, "\r\n", 2);

	write(fp, "Idade: ", 7*sizeof(char)); 
		for(i = 0 ; idade[i]; i++)
		{
			write(fp, &(idade[i]), 1); 
			
		}
	write(fp, " anos", 5);
	write(fp, "\r\n", 2);
	close(fp);
	return 0;
}
