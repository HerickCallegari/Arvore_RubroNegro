#include <stdio.h>
#include <stdlib.h>
#include "Arvore_RB.h"
int main()
{
    pDescArvore desc = criarArvore();
    insertNoh(desc,alocaInt(109), compInt);
    insertNoh(desc,alocaInt(110), compInt);
    insertNoh(desc,alocaInt(100), compInt);
    insertNoh(desc,alocaInt(105), compInt);
    insertNoh(desc,alocaInt(11), compInt);
    insertNoh(desc,alocaInt(102), compInt);
    insertNoh(desc,alocaInt(9), compInt);
    insertNoh(desc,alocaInt(16), compInt);


    printf("\nRemocao: %d", Remove(desc, alocaInt(100), compInt));
    desenhaArvore(desc, printaInt);
}
