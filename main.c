#include <stdio.h>
#include <stdlib.h>
#include "Arvore_RB.h"
int main()
{
    pDescArvore desc = criarArvore();
    insertNoh(desc,alocaInt(5), compInt);
    insertNoh(desc,alocaInt(4), compInt);
    insertNoh(desc,alocaInt(3), compInt);

    printf("\nRaiz procurada: ");
    printaInt(FindBy(desc, alocaInt(3), compInt)->info);
    desenhaArvore(desc, printaInt);
}
