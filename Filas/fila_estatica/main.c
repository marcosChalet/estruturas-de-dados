#include <stdio.h>
#include "fila.h"

int main () {
   
   Fila *fila = criar();
   Aluno al1 = {"Marcos", 123, 9, 8, 10};
   Aluno al2 = {"Socram", 321, 8, 6, 10};
   Aluno al3 = {"Chalet", 213, 9, 9, 10};

   inserir(fila, al1);
   inserir(fila, al2);
   inserir(fila, al3);
   inserir(fila, al3);


   printf("####### ANTES DAS REMOÇÕES #########\n\n");
   mostrar(fila);


   printf("####### APÓS ALGUMAS REMOÇÕES #########\n\n");
   remover(fila);
   remover(fila);
   mostrar(fila);


   printf("####### APÓS REMOVER TUDO #########\n\n");
   remover(fila);
   remover(fila);
   remover(fila);
   remover(fila);
   remover(fila);
   mostrar(fila);
   mostrar(fila);

   return 0;
}
