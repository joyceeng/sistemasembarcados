#include <stdio.h>

int main (void) {
   typedef struct { /*typedef � usada para nomear a struct como 'data'*/
      int dia, mes;/*dados dentro da estrutura*/
   } data;
   printf ("sizeof (data) = %d\n", /*printa o tamanho que � um inteiro da struct data*/
            sizeof (data));
return 0;
}
