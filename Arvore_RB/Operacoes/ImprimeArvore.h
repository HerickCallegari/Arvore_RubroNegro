
typedef void (*FuncaoImpressao) ( void* );

void imprimeArvoreRecursivo( pNohArvore raiz, FuncaoImpressao fip) {
    if ( raiz != NULL)
        fip(raiz->info);

    if ( raiz->direita != NULL) {
        printf(", ");

        imprimeArvoreRecursivo(raiz->direita, fip);
    }
    if ( raiz->esquerda != NULL) {
        printf(", ");
        imprimeArvoreRecursivo(raiz->esquerda, fip);
    }
}

void imprimeArvore( pDescArvore arvore, FuncaoImpressao fip) {
    printf("\nArvore: ");
    imprimeArvoreRecursivo(arvore->raiz, fip);
}

void desenhaArvoreRecursivo(pNohArvore raiz, int depth, char *path, int right, FuncaoImpressao fi) {

    if (raiz == NULL)
        return;

    depth++;

    desenhaArvoreRecursivo(raiz->direita, depth, path, 1, fi);

    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(raiz->esquerda)
        path[depth-1] = 1;

    printf("\n");
    int i;
    for(i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      int j;
      for(j=1; j<ESPACO; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    fi(raiz->info);
    printf("[%d]", raiz->cor);

    for(i=0; i<depth; i++)
    {
      if(path[i])
          printf(" ");
      else
          printf(" ");

      int j;
      for(j=1; j<ESPACO; j++)
          printf(" ");
    }

    desenhaArvoreRecursivo(raiz->esquerda, depth, path, 0, fi);
}

void DesenhaArvore(pDescArvore arvore, FuncaoImpressao fi) {
    char path[255] = {};

    desenhaArvoreRecursivo(arvore->raiz, 0, path, 0, fi);
    printf("\n");
}
