#include "utils.h"

#define ESPACO 5
// ############################### STRUCT ###############################
typedef struct NohArvoreRB NohArvore;
typedef NohArvore* pNohArvore;

typedef struct DescritorArvoreRB descArvore;
typedef descArvore* pDescArvore;


struct NohArvoreRB{
    void* info;
    pNohArvore direita;
    pNohArvore esquerda;
    pNohArvore pai;
    int cor; // vermelho = 0 | preto = 1
};

struct DescritorArvoreRB {
    pNohArvore raiz;
    int quantidade;
};

// ############################### Cabeçalhos ###############################

typedef int (*FuncaoComparacao) ( void*, void*);

typedef void (*FuncaoImpressao) ( void* );

pNohArvore tio ( pNohArvore raiz );

pNohArvore LeftLeft ( pNohArvore p);

pNohArvore LeftRigth(pNohArvore p);

pNohArvore RigthRigth(pNohArvore p);

pNohArvore RigthLeft(pNohArvore p);

// ############################### implementações ###############################

//------------------------------- Instaciar -------------------------------------------

pDescArvore criarArvore() {
    pDescArvore desc = malloc(sizeof(descArvore));
    desc->quantidade = 0;
    desc->raiz = NULL;
    return desc;
}

//------------------------------- Insert ---------------------------------------------

pNohArvore insertNohRecursivo(pNohArvore raiz, void* info, FuncaoComparacao fcp) {
    // Estrutura de inserção
    if (raiz == NULL) {
    printf("\nincluiu: ");
            //para teste
        pNohArvore noh = malloc(sizeof(NohArvore));
        noh->info = info;
        noh->cor = 0;
        noh->direita = NULL;
        noh->esquerda = NULL;
        noh->pai = NULL;

        return noh;
    }


    pNohArvore filho;
    if ( fcp ( info, raiz->info ) > 0) {
        filho = insertNohRecursivo(raiz->direita, info, fcp);
        if(filho->esquerda == raiz)
        {
            raiz = filho;
        }else {
        raiz->direita = filho;
        filho->pai = raiz;
        }

    }
    else {
        filho = insertNohRecursivo(raiz->esquerda, info, fcp);
        if(filho->direita == raiz)
        {
            raiz = filho;
        }else {
        raiz->esquerda = filho;
        filho->pai = raiz;
        }
    }


        //verificar se as condicoes sao validas
    if(raiz->cor == 1) {
        return raiz;
    }

    if ( raiz->pai == NULL) {
        raiz->cor = 1;
        return raiz;
    }

        //verificar quais condicoes foram violadas
    if ( raiz->cor == 0 && filho->cor == 0) {
        if ( tio(raiz) != NULL && tio(raiz)->cor == 0 ) {
            //recolorir o pai, tio e avô
            raiz->cor      = 1;
            tio(raiz)->cor = 1;
            raiz->pai      = 0;
            return raiz;
        } else {
            // Existem 4 casos possiveis caso o noh tenha um tio
            if ( raiz->pai->esquerda = raiz) {
                if (raiz->esquerda->pai == raiz)
                    return LeftLeft(raiz);
                else if ( raiz->direita->pai == raiz )
                    return LeftRigth(raiz);
            }

            if ( raiz->pai->direita = raiz) {
                if ( raiz->direita->pai == raiz )
                    return RigthRigth(raiz);
                else if (raiz->esquerda->pai == raiz)
                    return RigthLeft(raiz);
            }

        }
    }

    return raiz;

}

void insertNoh ( pDescArvore arvore, void* info, FuncaoComparacao fcp) {
    arvore->raiz = insertNohRecursivo(arvore->raiz, info, fcp);
    arvore->quantidade++;
}

//---------------------------- family ------------------------------

pNohArvore tio ( pNohArvore raiz ) {
    if(raiz == NULL)
        return NULL;


    if ( raiz->pai == NULL) {
        return NULL;
    }
    // Retorna o tio da raiz
    if(raiz->pai->esquerda == raiz) {
        return raiz->pai->direita;
    }
    else if ( raiz->pai->direita == raiz) {
        return raiz->pai->esquerda;
    }


    return NULL;

}
//------------------------------- Rotate --------------------------------------------

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

pNohArvore LeftRigth(pNohArvore p) {
    pNohArvore x = p->direita;
    pNohArvore g = p->pai;

        //recolorir
    g->cor = 0;
    p->cor = 0;
    x->cor = 1;

        //rotacao esquerda
    if ( x->esquerda != NULL) {
        p->direita = x->esquerda;
        p->direita->pai = p;
    }else {
    p->direita = NULL;
    }
    x->esquerda = p;
    g->esquerda = x;

        //rotacao direita
    if ( x->direita != NULL) {
    g->esquerda = x->direita;
    g->esquerda->pai = g;
    }else {
    g->esquerda = NULL;
    }
    x->direita = g;

        //troca os pais
    x->pai = g->pai;
    p->pai = x;
    g->pai = x;




    return x;
}

pNohArvore RigthRigth(pNohArvore p) {
    pNohArvore g = p->pai;

    //recolorir
    p->cor = 1;
    g->cor = 0;

    //rotacionar
    if (p->esquerda != NULL) {
        g->direita = p->esquerda;
        g->direita->pai = g;
    }else {
        g->direita = NULL;
    }
    p->esquerda = g;

    //trocar pais
    p->pai = g->pai;
    g->pai = p;

    return p;
}

pNohArvore RigthLeft(pNohArvore p) {
    pNohArvore g = p->pai;
    pNohArvore x = p->esquerda;

    //recolorir
    p->cor = 0;
    x->cor = 1;
    g->cor = 0;

    //trocar direita
    if ( x->direita != NULL) {
        p->esquerda = x->direita;
        p->esquerda->pai = p;
    }
    else {
        p->esquerda = NULL;
    }
    x->direita = p;
    g->direita = x;

    //trocar esquerda
    if ( x->esquerda != NULL) {
        g->direita = x->esquerda;
        g->direita->pai = g;
    }else {
    g->direita = NULL;
    }
    x->esquerda = g;

    //troca pai
    x->pai = g->pai;
    g->pai = x;
    p->pai = x;

    return x;
}
//------------------------------- print ---------------------------------------------

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

void desenhaArvore(pDescArvore arvore, FuncaoImpressao fi) {
    char path[255] = {};

    desenhaArvoreRecursivo(arvore->raiz, 0, path, 0, fi);
    printf("\n");
}

//--------------------------------------------------------------------------------
pNohArvore proxLeaf(pNohArvore raiz, void* info, FuncaoComparacao fcp) {
    if (raiz == NULL) {
            printf("raiz é nula");
        return NULL;
    }

    if ( raiz->direita != NULL && fcp(raiz->info, info) < 0) {
            return raiz->direita;
    }

    if ( raiz->esquerda != NULL && fcp( raiz->info, info ) > 0) {
            return raiz->esquerda;

    }

    return NULL;
}


pNohArvore FindByRecursivo(pNohArvore raiz, void* info, FuncaoComparacao fcp) {
    if (raiz == NULL) {
        return NULL; // Se raiz for nulo, não há mais nó para procurar
    }

    // Verifica se a raiz atual corresponde ao valor buscado
    if (fcp(raiz->info, info) == 0) {
        return raiz;
    }

    pNohArvore prox = proxLeaf(raiz, info, fcp);

    return FindByRecursivo(prox, info, fcp);

}



pNohArvore FindBy(pDescArvore arvore, void* info, FuncaoComparacao fcp) {
    return FindByRecursivo(arvore->raiz, info, fcp);;
}
