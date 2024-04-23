#include "StructArvore.h"

pDescArvore CriarArvore() {
    pDescArvore desc = malloc(sizeof(descArvore));
    desc->quantidade = 0;
    desc->raiz = NULL;
    return desc;
}
