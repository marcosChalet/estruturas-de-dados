#include <stdio.h>
#include "pilha.h"

typedef struct elemento {
   Aluno dados[MAX];
   int qtd;
}Elemento;

Pilha* criar() {
   Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));

   // indica como vazio o topo da pilha, caso a alocação dê certo
   if (pilha != NULL)
      pilha->qtd = 0;
   
   return pilha;
}

bool inserir(Pilha* pilha, Aluno novosDados) {

   if (pilha == NULL || pilha->qtd == MAX) // verifica se a pilha existe
      return false;

   pilha->dados[pilha->qtd] = novosDados;
   pilha->qtd++;

   return true;
}

bool remover(Pilha* pilha) {

   if (pilha == NULL || pilha->qtd == 0) // sair caso a fila não exista ou esteja vazia
      return false;

   pilha->qtd--;

   return true;
}

void mostrar(Pilha *pilha) {
   if (pilha == NULL) return;

   int i = pilha->qtd-1;
   while(i >= 0) {
      printf("Nome: %s, matricula: %d\nav1: %f\nav2: %f\nav3: %f\n\n", pilha->dados[i].nome, 
            pilha->dados[i].matricula, pilha->dados[i].av1, pilha->dados[i].av2, pilha->dados[i].av3);
      i--;
   }
}
