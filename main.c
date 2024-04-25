#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arvore_RB/Arvore_RB.h"
int main()
{
    pDescArvore desc = CriarArvore();

    for( int i = 0; i < 20; i++ ) {
    InsertNoh(desc, alocaInt(i), compInt);
    }
    InsertNoh(desc, alocaInt(21), compInt);
    InsertNoh(desc, alocaInt(70), compInt);
    InsertNoh(desc, alocaInt(-10), compInt);
    InsertNoh(desc, alocaInt(213), compInt);
    InsertNoh(desc, alocaInt(-2), compInt);
    InsertNoh(desc, alocaInt(-40), compInt);


    DesenhaArvore(desc, printaInt);

    printf("\n\n\n\nRemoveu: %d\n", RemoveInfo(desc, alocaInt(6), compInt));    printf("Removeu: %d\n", RemoveInfo(desc, alocaInt(70), compInt));
    printf("Removeu: %d\n\n\n\n------------------------------------------", RemoveInfo(desc, alocaInt(5), compInt));

    DesenhaArvore(desc, printaInt);

}
