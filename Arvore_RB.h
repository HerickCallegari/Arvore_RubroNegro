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
            return filho;
        }else {
        raiz->direita = filho;
        filho->pai = raiz;
        }

    }
    else {
        filho = insertNohRecursivo(raiz->esquerda, info, fcp);
        if(filho->direita == raiz)
        {
            return filho;
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
            if ( raiz->esquerda->pai == raiz) {
                printf("\ncaso 1: esquerda do noh e vermelho\n");

                        //para teste
                    printf("\nraiz: ");
                    printaInt(raiz->info);
                    printf("\nraiz->esquerda: ");
                    printaInt(raiz->esquerda->info);
                    printf("\nraiz->pai: ");
                    printaInt(raiz->pai->info);

                    return LeftLeft(raiz);
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
    if ( p->direita != NULL)
        g->esquerda = p->direita;
    else
        g->esquerda = NULL;

    p->direita = g;

        //trocando pais
    p->pai = g->pai;
    g->pai = p;

    return p;
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

