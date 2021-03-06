/*
 * Aqui há a implementação das funções de uma lista encadeada, que são:
 * inserir (início e fim), remover (inicio, fim e elemento específico),
 * recuperar, destruir lista e mostrar.
 *
 * Nota: ldse == NULL e *ldse == NULL representa que a lista não existe e
 * que a lista está vazia, respectivamente.
 * */

#include "listaEncadeada.h"

typedef struct elemento {
    struct aluno dados;
    struct elemento *prox;
}Elemento;

typedef struct elemento Elemento;

/*
 * Aloca uma lista e seta ela como vazia caso a alocação ocorra
 * correntamente.
 *
 * */

Lista* criar () {

    Lista *ldse;
    ldse = (Lista*)malloc(sizeof(Lista));

    if (ldse != NULL)
            *ldse = NULL;

    return ldse;
}


/* Verifica se a lista está vazia ou foi alocada */
bool vazia (Lista *ldse) {
    if((*ldse) != NULL)
        return false;

    return true;
}


bool inserirInicio (Lista *ldse, struct aluno novosDados) {

    if(ldse == NULL) {
        return false;
    }else {
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL) return false;

        novo->dados = novosDados;
        novo->prox = (*ldse);
        (*ldse) = novo;
    }

    return true;
}


bool inserirFim (Lista *ldse, struct aluno novosDados) {

    if(ldse == NULL) {
        return false;
    }

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    if(novo == NULL) return false;

    novo->dados = novosDados;
    novo->prox = NULL;
    if((*ldse) == NULL) {
        (*ldse) = novo;
    }else {
        Elemento *aux = (*ldse);
        while(aux->prox != NULL)
                aux = aux->prox;
        aux->prox = novo;
    }

    return true;
}


void destruirLista (Lista *ldse) {
    if(ldse != NULL) {
        Elemento *aux;
        while((*ldse) != NULL) {
            aux = *ldse;
            (*ldse) = (*ldse)->prox;
            free(aux);
        }
    }
}


bool removerElemento (Lista *ldse, int x) {

    if(vazia(ldse)) {
        return false;

    }else if((*ldse)->dados.matricula == x) {
        Elemento *aux = (*ldse);
        (*ldse) = (*ldse)->prox;
        free(aux);
    }else {

        Elemento *aux, *ant;
        aux = (*ldse);
        while(aux && aux->dados.matricula != x) {
            ant = aux;
            aux = aux->prox;
        }

        if(aux == NULL) return false;

        ant->prox = aux->prox;
        free(aux);
    }

    return true;
}


bool removerInicio (Lista *ldse) {

    if(ldse == NULL) return false;
    if(*ldse == NULL) return false;

    Elemento *aux = *ldse;
    *ldse = (*ldse)->prox;
    free(aux);

    return true;
}


bool removerFim (Lista *ldse) {

    if(ldse == NULL) return false;
    if(*ldse == NULL) return false;

    Elemento *aux =  (*ldse);
    if((*ldse)->prox == NULL) {
        *ldse = (*ldse)->prox;
        free(aux);
    }else {
        Elemento *ant = *ldse;
        aux = ant->prox;
        while(aux->prox != NULL) {
            ant = ant->prox;
            aux = aux->prox;
        }

        ant->prox = aux->prox;
        free(aux);
    }

    return true;
}


bool acessarIndice (Lista *ldse, int pos, struct aluno *aluno) {

    if(vazia(ldse)) {
        return false;
    }else if(pos < 0) {
        return false;
    }else {
        Elemento *aux = (*ldse);
        int cont = 0;
        while(aux && cont != pos) {
            aux = aux->prox;
        }

        if(aux != NULL) {
            (*aluno) = aux->dados;
        }
    }

    return true;
}


bool acessarValor (Lista *ldse, int x, struct aluno *aluno) {

    if(vazia(ldse)) {
        return false;
    }else {
        Elemento *aux = (*ldse);
        while(aux && aux->dados.matricula != x) {
            aux = aux->prox;
        }

        if(aux == NULL)
            return false;

        (*aluno) = aux->dados;
    }

    return true;
}


void mostrar (Lista *ldse) {
    if(ldse == NULL) return;
    if((*ldse) == NULL) return;

    Elemento *aux = (*ldse);
    printf("Lista -> ");
    while(aux) {
        printf("[%d] -> ", aux->dados.matricula);
        aux = aux->prox;
    }
    printf("||\n");
}

