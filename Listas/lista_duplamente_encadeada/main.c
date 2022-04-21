#include "listaDuplaEncadeada.h"
#include <stdio.h>

/*
 * Testando as funções da lista.
 * */

int main() {

    Lista *ldse = NULL;
    ldse = criar();

    struct aluno al;
    al.matricula = 54321;
    inserirOrdenado(ldse, al);

    al.matricula = 99281;
    inserirOrdenado(ldse, al);

    al.matricula = 32345;
    inserirOrdenado(ldse, al);

    al.matricula = 11111;
    inserirOrdenado(ldse, al);

    al.matricula = 99999;
    inserirOrdenado(ldse, al);

    removerInicio(ldse);
    removerFim(ldse);

    mostrar(ldse);

    return 0;
}
