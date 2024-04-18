pNohArvore LeftLeft ( pNohArvore p) {
    pNohArvore g = p->pai;

        //recolorindo
    p->cor = 1;
    g->cor = 0;

        //rotacao
    if ( p->direita != NULL) {
        g->esquerda = p->direita;
        g->esquerda->pai = g;
    }
    else {
        g->esquerda = NULL;
    }

    p->direita = g;

        //trocando pais
    p->pai = g->pai;
    g->pai = p;

    return p;
}

pNohArvore LeftRight(pNohArvore p) {
    pNohArvore x = p->direita;
    pNohArvore g = p->pai;

        //recolorir
    g->cor = 0;
    p->cor = 0;
    x->cor = 1;

        //rotacao esquerda
    p->direita = x->esquerda;
    if ( p->direita != NULL)
        p->direita->pai = p;

    g->esquerda = x->direita;
    if ( g->esquerda != NULL)
        g->esquerda->pai = g;

    x->direita = g;
    x->esquerda = p;

        //trocar pai
    x->pai = g->pai;
    p->pai = x;
    g->pai = x;

    return x;
}

pNohArvore RightRight(pNohArvore p) {
    pNohArvore g = p->pai;

        //recolorir
    p->cor = 1;
    g->cor = 0;

        //rotacionar
    g->direita = p->esquerda;
    if (p->esquerda != NULL) {
        g->direita->pai = g;
    }

    p->esquerda = g;

        //trocar pais
    p->pai = g->pai;
    g->pai = p;

    return p;
}

pNohArvore RightLeft(pNohArvore p) {
    pNohArvore g = p->pai;
    pNohArvore x = p->esquerda;

        //recolorir
    p->cor = 0;
    x->cor = 1;
    g->cor = 0;

        //rotacoes
    g->direita = x->esquerda;
    if ( g->direita != NULL ) {
        g->direita->pai = g;
    }

    p->esquerda = x->direita;
    if(p->esquerda != NULL) {
        p->esquerda->pai = p;
    }

    x->esquerda = g;
    x->direita = p;

        //troca pais
    x->pai = g->pai;
    g->pai = x;
    p->pai = x;

    return x;

}
