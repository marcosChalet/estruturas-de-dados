#include "listaEstatica.h"

int main () {

	Lista *lse;
	lse = NULL;
	lse = criar();
	struct aluno aluno;
/*
	aluno.matricula = 12345;
	inserirInicio(lse, aluno);

	aluno.matricula = 11111;
	inserirInicio(lse, aluno);

	aluno.matricula = 44411;
	inserirInicio(lse, aluno);

	aluno.matricula = 55555;
	inserirFim(lse, aluno);
*/

	aluno.matricula = 12345;
	inserirOrdenado(lse, aluno);

	aluno.matricula = 11111;
	inserirOrdenado(lse, aluno);

	aluno.matricula = 44411;
	inserirOrdenado(lse, aluno);

	aluno.matricula = 55555;
	inserirOrdenado(lse, aluno);

	aluno.matricula = 99925;
	inserirOrdenado(lse, aluno);

	aluno.matricula = 10000;
	inserirOrdenado(lse, aluno);

	removerInicio(lse);
	removerFim(lse);
	removerValor(lse, 44411);

	mostrar(lse);
	return 0;
}