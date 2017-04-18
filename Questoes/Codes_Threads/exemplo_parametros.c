#include <pthread.h>
#include <stdio.h>
struct char_print_parms /* define a estrutura e o que est� contido nela*/
{
char character;/* dentro da estrutura conter� char e int*/
int count;
};
void* char_print (void* parameters) /*um ponteiro do tipo void* para a fun��o char_print que coloca o par�metro dentro de char_print(fun��o) */
{
struct char_print_parms* p = (struct char_print_parms*) parameters; /*coloca os par�metros da fun��o dentro da vari�vel p*/
int i;
for (i = 0; i < p->count; ++i) /*imprime os caracteres armazenados na struct at� acabar o contador*/
printf("%c\n", p->character);
return NULL; /*retorna NULL porque � uma fun��o do tipo void*/
}
int main ()
{
pthread_t thread1_id; /* declara id*/
pthread_t thread2_id;
struct char_print_parms thread1_args;/*declarando o nome do registro*/
struct char_print_parms thread2_args;/*declarando o nome do registro 2*/
thread1_args.character = '1'; /*coloca no registro thread1_args o caractere 1*/
thread1_args.count = 3000;/*dolodq no registro thread2_args o caractere 2*/
pthread_create (&thread1_id, NULL, &char_print, &thread1_args); /*cria o thread, passa o endere�o da thread_id, o endere�o da fun��o do tipo void e endere�o do registro da thread1_args*/
thread2_args.character = '-'; /*coloca caractere - dentro do registro thread2_args no campo caractere*/
thread2_args.count = 2000; /*coloca 2000 dentro do registro thread2_args no campo count*/
pthread_create (&thread2_id, NULL, &char_print, &thread2_args); (/*cria nova thread e passa os endere�os da fun��o e do registro*/)
return 0;
}