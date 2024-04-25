#ifndef ROTACOES_ARVORE_RUBRO_NEGRA_H
#define ROTACOES_ARVORE_RUBRO_NEGRA_H

/* ---------------------------------------------------------------------*/
pNohArvore avo(pNohArvore raiz){
    if (raiz == NULL)
        return NULL;

    if (raiz->pai == NULL)
        return NULL;

    return raiz->pai->pai;
}

/* ---------------------------------------------------------------------*/
pNohArvore tio(pNohArvore raiz){
   if (raiz == NULL || raiz->pai == NULL)
     return NULL;

  // o filho da esquerda do pai da raiz é a própria raiz,
  // então retorna o filho da direita
  if (avo(raiz) != NULL && avo(raiz)->esquerda == raiz->pai)
    return avo(raiz)->direita;

  return avo(raiz)->esquerda;
}

/* ---------------------------------------------------------------------*/
int corTio(pNohArvore raiz){
   pNohArvore tioRaiz = tio(raiz);
   if (tioRaiz == NULL)
       return -1;

   return tioRaiz->cor;
}

/* ---------------------------------------------------------------------*/
pNohArvore Irmao(pNohArvore raiz) {
    pNohArvore pai = raiz->pai;

    if ( pai == NULL)
        return NULL;

    if ( pai->direita == NULL || pai->esquerda == NULL)
        return NULL;

    if ( pai->direita == raiz)
        return pai->esquerda;
    else
        return pai->direita;
}

//----------------------------------


pNohArvore Right(pNohArvore raiz){ // a raiz é o filho

    // se não tem pai e avô, não rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
        return NULL;

    pNohArvore avoRaiz = avo(raiz);

    // altera a paternidade do filho e do pai
    avoRaiz->pai   = raiz->pai;
    raiz->pai->pai = avoRaiz->pai;

    // ajusta as sub-arvores da raiz
    avoRaiz->esquerda  = raiz->pai->direita;
    raiz->pai->direita = avoRaiz;

    // ajusta as cores
    raiz->pai->cor  = 1;
    avoRaiz->cor    = 0;

    return raiz->pai;
}

//----------------------------------
pNohArvore Left(pNohArvore raiz){

     // se não tem pai e avô, não rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
        return NULL;

    pNohArvore avoRaiz = avo(raiz);

    // altera a paternidade do filho e do pai
    raiz->pai->pai = avoRaiz->pai;
    avoRaiz->pai   = raiz->pai;


    // ajusta as sub-arvores da raiz
    avoRaiz->direita    = raiz->pai->esquerda;
    raiz->pai->esquerda = avoRaiz;

    // ajusta as cores
    raiz->pai->cor  = 1;
    avoRaiz->cor    = 0;

    return raiz->pai;
}


//----------------------------------
pNohArvore RightLeft(pNohArvore raiz){

    // se não tem pai e nem avô, não rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
        return NULL;

    pNohArvore avoRaiz = avo(raiz);
    pNohArvore paiRaiz = raiz->pai;

    // altera a paternidade do filho e do pai
    paiRaiz->pai = raiz;
    raiz->pai    = avoRaiz;

    // ajusta as sub-arvores do filho(raiz) e do pai
    paiRaiz->esquerda = raiz->direita;
    raiz->direita     = paiRaiz;

    // rotação simples a esquerda
    return Left(paiRaiz);


}
//----------------------------------
pNohArvore LeftRight(pNohArvore raiz){

  // se não tem pai e nem avô, não rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
       return NULL;

    pNohArvore avoRaiz = avo(raiz);
    pNohArvore paiRaiz = raiz->pai;

    // altera a paternidade do filho e do pai
    paiRaiz->pai = raiz;
    raiz->pai    = avoRaiz;

    // ajusta as sub-arvores do filho(raiz) e do pai
    paiRaiz->direita = raiz->esquerda;
    raiz->esquerda   = paiRaiz;

    // rotação simples a direita
    return Right(paiRaiz);
}

#endif
