#ifndef _LISTAESTATICA_H
#define _LISTAESTATICA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct aluno {
    char nome[50];
    int matricula;
    float av1;
    float av2;
    float av3;
};

typedef struct lista Lista;

Lista* criar ();
void destruir (Lista *);

int tamanho (Lista *);
int cheia (Lista *);
int vazia (Lista *);

int inserirFim (Lista *, struct aluno );
int inserirInicio (Lista *, struct aluno );
int inserirOrdenado (Lista *, struct aluno );

int removerFim (Lista *);
int removerInicio (Lista *);
int removerValor (Lista *, int);

int acessarIndice (Lista *, int , struct aluno *);
int acessarValor (Lista *, int , struct aluno *);

void mostrar (Lista *);

#endif
