#include <stdio.h>
#include "fila.h"

typedef struct elemento {
   struct aluno dados;
   struct elemento *prox;
}Elemento;


typedef struct node {
   struct elemento *inicio;
   struct elemento *fim;
}Fila;

Fila* criar() {
   Fila* fila = (Fila*)malloc(sizeof(struct node));

   // caso a alocação dê certo, seta como vazia o início da lista
   if (fila != NULL) {
      fila->inicio = NULL;
      fila->fim = NULL;
   }
  
   return fila;
}

bool inserir(Fila* fila, Aluno novosDados) {

   if (fila == NULL) // verificando se a fila existe
      return false;

   Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
   if (novo == NULL) 
      return false;

   novo->dados = novosDados;
   novo->prox = NULL;

   if (fila->inicio != NULL)  //adiciona o novo elemento na fila com elementos
      fila->fim->prox = novo;

   else //adiciona o novo elemento na fila vazia
      fila->inicio = novo;

   // em todo caso, o fim da fila será o novo elemento.
   fila->fim = novo;

   return true;
}

bool remover(Fila* fila) {
   
   // sair da função caso a fila não exista ou for vazia
   if (fila == NULL || fila->inicio == NULL) return false;

   Elemento *aux = fila->inicio;
   fila->inicio = fila->inicio->prox;

   free(aux);

   return true;
}

void mostrar(Fila* fila) {

   if (fila == NULL) return;

   Elemento *aux = fila->inicio;

   for (;aux != NULL;) {
      printf("Nome: %s, matricula: %d\nav1: %f\nav2: %f\nav3: %f\n\n", aux->dados.nome, 
            aux->dados.matricula, aux->dados.av1, aux->dados.av2, aux->dados.av3);

      aux = aux->prox;
   }
}
