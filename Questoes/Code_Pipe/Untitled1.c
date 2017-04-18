#include <stdio.h>

int main (void) {
   typedef struct { /*typedef é usada para nomear a struct como 'data'*/
      int dia, mes;/*dados dentro da estrutura*/
   } data;
   printf ("sizeof (data) = %d\n", /*printa o tamanho que é um inteiro da struct data*/
            sizeof (data));
return 0;
}
