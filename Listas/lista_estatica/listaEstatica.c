/*
 * Aqui há a implementação das funções de uma lista estática, que são:
 * inserir (início, fim e ordenado), remover (inicio, fim e elemento 
 * específico), recuperar, destruir lista e mostrar.
 *
 * Nota: ldde == NULL e *ldde == NULL representa que a lista não existe
 * e que a lista está vazia, respectivamente.
 * */

#include "listaEstatica.h"

struct lista {
	int qtd;
    struct aluno dados[MAX];
};

Lista* criar () {
    /*
     * Aloca uma lista e seta ela como vazia caso a alocação ocorra
     * correntamente.
     * */

    Lista *lse;
    lse = (Lista*)malloc(sizeof(Lista));

    if (lse != NULL)
            lse->qtd = 0;

    return lse;
}


void destruir (Lista *lse) {
	free(lse);
}


int tamanho (Lista *lse) {
	if (lse == NULL)
		return -1;
	return lse->qtd;
}


int cheia (Lista *lse) {
	if (lse == NULL)
		return -1;
	else if (lse->qtd == MAX)
		return 1;
	else
		return 0;
}


int vazia (Lista *lse) {
	if (lse == NULL)
		return -1;
	else if (lse->qtd == 0)
		return 1;
	else
		return 0;
}


int inserirFim (Lista *lse, struct aluno novo) {

	if (lse == NULL) {
		return 0;
	}
	else if (cheia(lse)) {
		return 0;
	}
	else {
		lse->dados[lse->qtd] = novo;
		lse->qtd++;
	}
	return 1;
}


int inserirInicio (Lista *lse, struct aluno novo) {
	if (lse == NULL) {
		return 0;
	}
	else if (cheia(lse)) {
		return 0;
	}
	else {
		int i;
		for (i = (lse->qtd)-1; i >= 0; i--) {
			lse->dados[i+1] = lse->dados[i];
		}
		lse->dados[0] = novo;
		lse->qtd++;
	}
	return 1;
}


int inserirOrdenado (Lista *lse, struct aluno novo) {
	if (lse == NULL) {
		return 0;
	}
	else if (cheia(lse)) {
		return 0;
	}
	else {
		int i, pos = 0;

		while (lse->dados[pos].matricula < novo.matricula && pos < lse->qtd)
			pos++;

		for (i = (lse->qtd)-1; i >= pos; i--) {
			lse->dados[i+1] = lse->dados[i];
		}
		lse->dados[pos] = novo;
		lse->qtd++;
	}
	return 1;
}


int removerFim (Lista *lse) {
	if (lse == NULL)
		return 0;
	else if (vazia(lse))
		return 0;
	else
		lse->qtd--;

	return 1;
}


int removerInicio (Lista *lse) {
	if (lse == NULL) {
		return 0;
	}
	else if (vazia(lse)) {
		return 0;
	}
	else {
		int i;
		for (i = 0; i < lse->qtd-1; i++)
			lse->dados[i] = lse->dados[i+1];
		lse->qtd--;
	}
	return 1;
}


int removerValor (Lista *lse, int x) {
	if (lse == NULL) {
		return 0;
	}
	else if (vazia(lse)) {
		return 0;
	}
	else {
		int i, pos = 0;

		while (lse->dados[pos].matricula != x && pos < lse->qtd)
			pos++;

		if (pos == lse->qtd)
			return 0;

		for (i = pos; i < lse->qtd-1; i++)
			lse->dados[i] = lse->dados[i+1];
		lse->qtd--;
	}
	return 1;
}


int acessarIndice (Lista *lse, int pos, struct aluno *a) {
	if (lse == NULL)
		return 0;
	else if (pos < 0 || pos >= lse->qtd)
		return 0;
	else
		*a = lse->dados[pos];

	return 1;
}


int acessarValor (Lista *lse, int x, struct aluno *a) {
	if (lse == NULL) {
		return 0;
	}
	else {
		int pos = 0;

		while (lse->dados[pos].matricula != x && pos < lse->qtd)
			pos++;

		if (pos == lse->qtd)
			return 0;
		else
			*a = lse->dados[pos];
	}
	return 1;
}


void mostrar (Lista *lse) {
    if(lse == NULL) return;
    if(vazia(lse)) return;

    /* Mostra do início até o fim */
    int cont = 0;

    printf("Lista -> ");
    while (cont < lse->qtd-1) {
        printf("[%d] -> ", lse->dados[cont].matricula);
        cont++;
    }
    printf("[%d] -> ||\n", lse->dados[cont].matricula);


    /* Mostra do fim até o início */
    printf("Lista -> ");
    while(cont >= 0) {
        printf("[%d] -> ", lse->dados[cont].matricula);
        cont--;
    }
    printf("||\n");
}