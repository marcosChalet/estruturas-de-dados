#ifndef _FILA_H
#define _FILA_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct aluno {
   char nome[50];
   int matricula;
   double av1;
   double av2;
   double av3;
}Aluno;

typedef struct elemento Fila;

Fila* criar();
bool inserir(Fila*, Aluno);
bool remover(Fila*);
void mostrar(Fila*);

#endif
