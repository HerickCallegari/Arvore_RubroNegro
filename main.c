#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arvore_RB/Arvore_RB.h"
int main()
{
    pDescArvore desc = CriarArvore();

    for( int i = 0; i < 10; i++ ) {
    int num = (rand());
    InsertNoh(desc, alocaInt(num), compInt);
    }

    DesenhaArvore(desc, printaInt);

}
