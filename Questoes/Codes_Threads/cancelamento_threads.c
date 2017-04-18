#include <stdio.h> /*entrada e sa�da padr�o*/
#include <stdlib.h>
#include <pthread.h> /*Todas as fun��es de threads e tipos de dados s�o declarados aqui*/
#include <unistd.h>

void *thread_function(void *arg); /*chamada da fun��o*/
int main(){
	int res; /*inteiro do resultado se foi poss�vel terminar a thread*/
	pthread_t a_thread; /* thread de processo � identificada como um thread ID chamada por ex pthread_t)*/
	void *thread_result; /* declara ponteiro para resultado*/
	res = pthread_create(&a_thread, NULL, thread_function, NULL); /* pega o ID da thread e chama a fun��o thread // deve ser NULL porque a_thread e thread_function s�o do tipo void */
	if (res != 0){ /* o resultado deve ser 1 
	perror ("N�o foi poss�vel criar a thread!");
	exit(EXIT_FAILURE);
	}
	sleep(5); /*delay*/
	printf("Cancelando a thread... \n");
	res = pthread_cancel(a_thread); /*chama a fun��o cancel e o par�metro � o nome da thread_ID > a_thread*/
	if (res != 0){
		perror("N�o foi poss�vel cancelar a thread!");
		exit(EXIT_FAILURE);
	}
	printf("Esperando o fim da execu��o da thread...\n");
	res = pthread_join(a_thread, &thread_result); /*res recebe a chamada da fun��o de espera (para for�ar que a main funcione at� a thread desejada parar). Como par�metro recebe a thread_ID da thread que ir� esperar e um ponteiro para void que recebe o valor de retorno da thread*/
	if (res != 0){
		perror ("N�o foi poss�vel juntar as threads!");
		exit(EXIT_FAILURE);
	}
}

void *thread_function(void *arg){ /*declara��o da fun��o*/
	int i, res;
	res = phtread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); /*fun��o setcancelstate seta 1 para enable, ou seja, pode cancelar, mas retorna NULL*/
	if (res != 0){
		perror ("Falha na pthread_setcancelstate");
		exit(EXIT_FAILURE);
	}
res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); /*fun��o canceltype seta 1 da canceldeferred (adia o cancelamento)*/
	if (res != 0){
		perror ("Falha na pthread_setcanceltype");
		exit(EXIT_FAILURE);
	}
printf("Fun��o thread executando. \n");
	for (i  = 0; i < 10; i++){
		printf ("Thread em execu��o (%d)... \n", i);
		sleep(1); /*espera 1 segundo*/
	}
pthread_exit(0);
}

