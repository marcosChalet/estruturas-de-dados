#include "listaEncadeada.h"
#include <stdio.h>

/*
 * Testando as funções da lista.
 * */

int main() {

    Lista *ldse = NULL;
    ldse = criar();

    struct aluno al;
    al.matricula = 54321;

    al.matricula = 54321;
    inserirInicio(ldse, al);

    al.matricula = 12345;
    inserirInicio(ldse, al);

    al.matricula = 33333;
    inserirFim(ldse, al);

    al.matricula = 99999;
    inserirFim(ldse, al);

    // removerElemento(ldse, 33333);
    // removerInicio(ldse);
    removerFim(ldse);

    // destruirLista(ldse);
    mostrar(ldse);

    return 0;
}
