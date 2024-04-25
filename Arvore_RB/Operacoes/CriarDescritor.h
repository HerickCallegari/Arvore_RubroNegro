#ifndef CRIAR_ARVORE_RUBRO_NEGRA_H
#define CRIAR_ARVORE_RUBRO_NEGRA_H

#include "../Arvore_RB.h"

pDescArvore CriarArvore() {
    pDescArvore desc = malloc(sizeof(descArvore));
    desc->quantidade = 0;
    desc->raiz = NULL;
    return desc;
}

#endif // CRIAR_ARVORE_RUBRO_NEGRA_H
