#include <stdio.h>
#include <stdlib.h>
#include "Arvore_RB/Arvore_RB.h"
int main()
{
    pDescArvore desc = criarArvore();


    for( int i = 0; i < 10; i++ ) {
    int num = (rand() % 1001) - 1;
    insertNoh(desc, alocaInt(num), compInt);
    }
    insertNoh(desc, alocaInt(16), compInt);
    insertNoh(desc, alocaInt(-20), compInt);
    insertNoh(desc, alocaInt(-15), compInt);

    insertNoh(desc, alocaInt(10), compInt);
    insertNoh(desc, alocaInt(8), compInt);
    insertNoh(desc, alocaInt(9), compInt);
    desenhaArvore(desc, printaInt);
}
