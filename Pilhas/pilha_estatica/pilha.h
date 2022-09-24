#ifndef _PILHA_H
#define _PILHA_H

#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct aluno {
   char nome[50];
   int matricula;
   double av1;
   double av2;
   double av3;
}Aluno;

typedef struct elemento Pilha;

Pilha* criar();
bool inserir(Pilha*, Aluno);
bool remover(Pilha*);
void mostrar(Pilha*);

#endif
