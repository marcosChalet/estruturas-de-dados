#ifndef _LISTAENCADEADA_H
#define _LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct aluno {
    char nome[50];
    int matricula;
    float av1;
    float av2;
    float av3;
};

typedef struct elemento* Lista;

Lista* criar ();
bool vazia (Lista *);

bool inserirInicio (Lista *, struct aluno);
bool inserirFim (Lista *, struct aluno);

void destruirLista (Lista *);
bool removerElemento (Lista *, int);
bool removerInicio (Lista *);
bool removerFim (Lista *);

bool acessarIndice (Lista *, int, struct aluno *);
bool acessarValor (Lista *, int, struct aluno *);

void mostrar (Lista *);

#endif
