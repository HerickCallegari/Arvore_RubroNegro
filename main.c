#include <stdio.h>
#include <stdlib.h>
#include "Arvore_RB.h"
int main()
{
    pDescArvore desc = criarArvore();
    insertNoh(desc,alocaInt(105), compInt);
    insertNoh(desc,alocaInt(16), compInt);
    insertNoh(desc,alocaInt(110), compInt);
    insertNoh(desc,alocaInt(111), compInt);
    insertNoh(desc,alocaInt(106), compInt);
    insertNoh(desc,alocaInt(102), compInt);
    insertNoh(desc,alocaInt(9), compInt);
    insertNoh(desc,alocaInt(10), compInt);

    Remove(desc, alocaInt(105), compInt);

    desenhaArvore(desc, printaInt);
}
