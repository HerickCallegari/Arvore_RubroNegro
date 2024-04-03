#include <stdio.h>
#include <stdlib.h>
#include "Arvore_RB.h"
int main()
{
    pDescArvore desc = criarArvore();
    insertNoh(desc,alocaInt(5), compInt);
    insertNoh(desc,alocaInt(3), compInt);
    insertNoh(desc,alocaInt(8), compInt);
    insertNoh(desc,alocaInt(9), compInt);
    insertNoh(desc,alocaInt(10), compInt);

    desenhaArvore(desc, printaInt);
}
