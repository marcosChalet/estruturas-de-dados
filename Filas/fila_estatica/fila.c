#include <stdio.h>
#include "fila.h"

#define MAX 30

typedef struct elemento {
   Aluno dados[MAX];
   int qtd;
}Elemento;


Fila* criar() {
   Fila* fila = (Fila*)malloc(sizeof(Fila));

   // caso a alocação dê certo, setar como 0 o total de elementos
   if (fila != NULL) {
      fila->qtd = 0;
   }
  
   return fila;
}

bool inserir(Fila* fila, Aluno novosDados) {

   if (fila == NULL) // verificando se a fila existe
      return false;

   if (fila->qtd == MAX) {
      printf("Fila cheia...\n");
      return false;
   }

   fila->dados[fila->qtd] = novosDados;
   fila->qtd++;

   return true;
}

bool remover(Fila* fila) {
   
   // sair da função caso a fila não exista ou for vazia
   if (fila == NULL || fila->qtd == 0) return false;

   int i = 0;
   while(i < fila->qtd) {
      fila->dados[i] = fila->dados[i+1];
      i++;
   }

   fila->qtd--;

   return true;
}

void mostrar(Fila* fila) {

   if (fila == NULL) return;

   for (int i = 0; i < fila->qtd; i++) {
      printf("Nome: %s, matricula: %d\nav1: %f\nav2: %f\nav3: %f\n\n", fila->dados[i].nome, 
            fila->dados[i].matricula, fila->dados[i].av1, fila->dados[i].av2, fila->dados[i].av3);
   }
}

