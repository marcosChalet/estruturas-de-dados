#include <stdio.h>
#include "pilha.h"

int main() {

   Pilha *pilha = criar();

   Aluno al1 = {"Marcos", 123, 9, 8, 10};
   Aluno al2 = {"Socram", 321, 8, 6, 10};
   Aluno al3 = {"Chalet", 213, 9, 9, 10};

   inserir(pilha, al1);
   inserir(pilha, al2);
   inserir(pilha, al3);
   inserir(pilha, al3);


   printf("####### ANTES DAS REMOÇÕES #########\n\n");
   mostrar(pilha);


   printf("####### APÓS ALGUMAS REMOÇÕES #########\n\n");
   remover(pilha);
   remover(pilha);
   mostrar(pilha);


   printf("####### APÓS REMOVER TUDO #########\n\n");
   remover(pilha);
   remover(pilha);
   remover(pilha);
   remover(pilha);
   remover(pilha);
   mostrar(pilha);
   mostrar(pilha);

   return 0;
}
