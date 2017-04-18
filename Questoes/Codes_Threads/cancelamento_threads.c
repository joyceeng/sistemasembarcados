#include <stdio.h> /*entrada e saída padrão*/
#include <stdlib.h>
#include <pthread.h> /*Todas as funções de threads e tipos de dados são declarados aqui*/
#include <unistd.h>

void *thread_function(void *arg); /*chamada da função*/
int main(){
	int res; /*inteiro do resultado se foi possível terminar a thread*/
	pthread_t a_thread; /* thread de processo é identificada como um thread ID chamada por ex pthread_t)*/
	void *thread_result; /* declara ponteiro para resultado*/
	res = pthread_create(&a_thread, NULL, thread_function, NULL); /* pega o ID da thread e chama a função thread // deve ser NULL porque a_thread e thread_function são do tipo void */
	if (res != 0){ /* o resultado deve ser 1 
	perror ("Não foi possível criar a thread!");
	exit(EXIT_FAILURE);
	}
	sleep(5); /*delay*/
	printf("Cancelando a thread... \n");
	res = pthread_cancel(a_thread); /*chama a função cancel e o parâmetro é o nome da thread_ID > a_thread*/
	if (res != 0){
		perror("Não foi possível cancelar a thread!");
		exit(EXIT_FAILURE);
	}
	printf("Esperando o fim da execução da thread...\n");
	res = pthread_join(a_thread, &thread_result); /*res recebe a chamada da função de espera (para forçar que a main funcione até a thread desejada parar). Como parâmetro recebe a thread_ID da thread que irá esperar e um ponteiro para void que recebe o valor de retorno da thread*/
	if (res != 0){
		perror ("Não foi possível juntar as threads!");
		exit(EXIT_FAILURE);
	}
}

void *thread_function(void *arg){ /*declaração da função*/
	int i, res;
	res = phtread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); /*função setcancelstate seta 1 para enable, ou seja, pode cancelar, mas retorna NULL*/
	if (res != 0){
		perror ("Falha na pthread_setcancelstate");
		exit(EXIT_FAILURE);
	}
res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); /*função canceltype seta 1 da canceldeferred (adia o cancelamento)*/
	if (res != 0){
		perror ("Falha na pthread_setcanceltype");
		exit(EXIT_FAILURE);
	}
printf("Função thread executando. \n");
	for (i  = 0; i < 10; i++){
		printf ("Thread em execução (%d)... \n", i);
		sleep(1); /*espera 1 segundo*/
	}
pthread_exit(0);
}

