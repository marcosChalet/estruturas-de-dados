#include <stdio.h>
#include "pilha.h"

typedef struct elemento {
   Aluno dados;
   struct elemento *prox;
}Elemento;


Pilha* criar() {
   Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));

   // indica como vazio o topo da pilha, caso a alocação dê certo
   if (pilha != NULL)
      *pilha = NULL;
   
   return pilha;
}

bool inserir(Pilha* pilha, Aluno novosDados) {

   if (pilha == NULL) // verifica se a pilha existe
      return false;


   Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
   if (novo == NULL) return false;

   novo->dados = novosDados;

   novo->prox = *pilha;
   *pilha = novo;

   return true;
}

bool remover(Pilha* pilha) {

   if (pilha == NULL || *pilha == NULL) // sair caso a fila não exista ou esteja vazia
      return false;

   Elemento *aux = *pilha;
   *pilha = (*pilha)->prox;

   free(aux);

   return true;
}

void mostrar(Pilha *pilha) {
   if (pilha == NULL) return;

   Elemento *aux = *pilha;

   while(aux) {
      printf("Nome: %s, matricula: %d\nav1: %f\nav2: %f\nav3: %f\n\n", aux->dados.nome, 
            aux->dados.matricula, aux->dados.av1, aux->dados.av2, aux->dados.av3);
      aux = aux->prox;
   }
}
