/*
 * Aqui há a implementação das funções de uma lista duplamente encadeada,
 * que são: inserir (início e fim), remover (inicio, fim e elemento específico),
 * recuperar, destruir lista e mostrar.
 *
 * Nota: ldde == NULL e *ldde == NULL representa que a lista não existe e
 * que a lista está vazia, respectivamente.
 * */

#include "listaDuplaEncadeada.h"

typedef struct elemento {
    struct aluno dados;
    struct elemento *prox;
    struct elemento *ant;
}Elemento;

typedef struct elemento Elemento;


Lista* criar () {
    /*
     * Aloca uma lista e seta ela como vazia caso a alocação ocorra
     * correntamente.
     * */

    Lista *ldde;
    ldde = (Lista*)malloc(sizeof(Lista));

    if (ldde != NULL)
            *ldde = NULL;

    return ldde;
}


/* Verifica se a lista está vazia ou foi alocada */
bool vazia (Lista *ldde) {
    if((*ldde) != NULL)
        return false;

    return true;
}


bool inserirInicio (Lista *ldde, struct aluno novosDados) {

    if(ldde == NULL)
        return false;

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    if(novo == NULL) return false;

    novo->dados = novosDados;
    novo->prox = (*ldde);
    novo->ant = NULL;

    if(*ldde != NULL)
        (*ldde)->ant = novo;

    (*ldde) = novo;

    return true;
}


bool inserirFim (Lista *ldde, struct aluno novosDados) {

    if(ldde == NULL) {
        return false;
    }

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    if(novo == NULL) return false;

    novo->dados = novosDados;
    novo->prox = NULL;
    if((*ldde) == NULL) {
        novo->ant = NULL;
        (*ldde) = novo;
    }else {
        Elemento *aux = (*ldde);
        while(aux->prox != NULL)
                aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }

    return true;
}


bool inserirOrdenado (Lista *ldde, struct aluno novosDados) {

    if(ldde == NULL)
        return false;

    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL)
        return false;

    novo->dados = novosDados;

    if (*ldde == NULL || (*ldde)->dados.matricula > novosDados.matricula) {
        /* Inserir no início. */
        novo->ant = NULL;
        novo->prox = *ldde;
        if(*ldde != NULL)
            (*ldde)->ant = novo;
        *ldde = novo;
    } else {
        /* Inserir no meio ou no fim */
        Elemento *ant = *ldde;
        Elemento *aux = ant->prox;
        while (aux != NULL && aux->dados.matricula < novosDados.matricula) {
            ant = ant->prox;
            aux = aux->prox;
        }
        ant->prox = novo;
        if (aux != NULL) //caso seja adicionado no meio
            aux->ant = novo;

        novo->ant = ant;
        novo->prox = aux;
    }

    return true;
}


void destruirLista (Lista *ldde) {
    if(ldde != NULL) {
        Elemento *aux;
        while((*ldde) != NULL) {
            aux = *ldde;
            (*ldde) = (*ldde)->prox;
            free(aux);
        }
    }
}


bool removerElemento (Lista *ldde, int x) {

    if(vazia(ldde)) {
        return false;

    }else if((*ldde)->dados.matricula == x) {
        Elemento *aux = (*ldde);
        (*ldde) = (*ldde)->prox;
        free(aux);
    }else {

        Elemento *aux, *ant;
        aux = (*ldde);
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


bool removerInicio (Lista *ldde) {

    if(ldde == NULL) return false;
    if(*ldde == NULL) return false;

    Elemento *aux = *ldde;
    *ldde = (*ldde)->prox;

    if (aux->prox != NULL) {
        /* caso a lista tenha mais de um elemento, o ponteiro ant
         * da elemento cabeça da lista deve apontar para NULL*/
        aux->prox->ant = NULL;
    }

    free(aux);

    return true;
}


bool removerFim (Lista *ldde) {

    if(ldde == NULL) return false;
    if(*ldde == NULL) return false;

    Elemento *aux = *ldde;
    if((*ldde)->prox == NULL) { // há apenas um elemento.
        *ldde = (*ldde)->prox;
        free(aux);
    }else {
        Elemento *ant = *ldde;
        while(aux->prox != NULL)
            aux = aux->prox;

        aux->ant->prox = NULL;
        free(aux);
    }

    return true;
}


bool acessarIndice (Lista *ldde, int pos, struct aluno *aluno) {

    if(vazia(ldde)) {
        return false;
    }else if(pos < 0) {
        return false;
    }else {
        Elemento *aux = (*ldde);
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


bool acessarValor (Lista *ldde, int x, struct aluno *aluno) {

    if(vazia(ldde)) {
        return false;
    }else {
        Elemento *aux = (*ldde);
        while(aux && aux->dados.matricula != x) {
            aux = aux->prox;
        }

        if(aux == NULL)
            return false;

        (*aluno) = aux->dados;
    }

    return true;
}


void mostrar (Lista *ldde) {
    if(ldde == NULL) return;
    if((*ldde) == NULL) return;

    /* Mostra do início até o fim */
    Elemento *aux = (*ldde);
    printf("Lista -> ");
    while(aux->prox != NULL) {
        printf("[%d] -> ", aux->dados.matricula);
        aux = aux->prox;
    }
    printf("[%d] -> ||\n", aux->dados.matricula);


    /* Mostra do fim até o início */
    printf("Lista -> ");
    while(aux != NULL) {
        printf("[%d] -> ", aux->dados.matricula);
        aux = aux->ant;
    }
    printf("||\n");
}

