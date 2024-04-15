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

pNohArvore Irmao ( pNohArvore raiz );

pNohArvore LeftLeft ( pNohArvore p);

pNohArvore LeftRight(pNohArvore p);

pNohArvore RightRight(pNohArvore p);

pNohArvore RightLeft(pNohArvore p);

int isLeaf(pNohArvore raiz);

void freeNoh(pNohArvore raiz);

pNohArvore PreNoh(pNohArvore raiz);

pNohArvore FindBy(pDescArvore arvore, void* info, FuncaoComparacao fcp);
// ############################### implementações ###############################

void freeNoh(pNohArvore raiz) {
    raiz->pai = NULL;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    free(raiz->info);
    free(raiz->esquerda);
    free(raiz->direita);
    free(raiz->pai);
    free(raiz);
}

//------------------------------- Instaciar -------------------------------------------

pDescArvore criarArvore() {
    pDescArvore desc = malloc(sizeof(descArvore));
    desc->quantidade = 0;
    desc->raiz = NULL;
    return desc;
}

//------------------------------- Insert ---------------------------------------------

pNohArvore insertNohRecursivo(pNohArvore raiz, void* info, FuncaoComparacao fcp) {
    if (raiz == NULL) {
        pNohArvore noh = malloc(sizeof(NohArvore));
        noh->info = info;
        noh->cor = 0;
        noh->direita = NULL;
        noh->esquerda = NULL;
        noh->pai = NULL;
        return noh;
    }

    pNohArvore filho;
    if (fcp(info, raiz->info) > 0) {
        filho = insertNohRecursivo(raiz->direita, info, fcp);
        raiz->direita = filho;
        filho->pai = raiz;
    } else {
        filho = insertNohRecursivo(raiz->esquerda, info, fcp);
        raiz->esquerda = filho;
        filho->pai = raiz;
    }

    if (raiz->cor == 1) {
        return raiz;
    }

    if (raiz->pai == NULL) {
        raiz->cor = 1;
        return raiz;
    }

    if (raiz->cor == 0 && filho->cor == 0) {
        if (Irmao(raiz) != NULL && Irmao(raiz)->cor == 0) {
            raiz->cor = 1;
            Irmao(raiz)->cor = 1;
            raiz->pai->cor = 0;
            return raiz;
        } else {
            if (raiz->pai->esquerda == raiz) {
                if (filho == raiz->esquerda)
                    return LeftLeft(raiz->pai);
                else if (filho == raiz->direita)
                    return LeftRight(raiz->pai);
            }

            if (raiz->pai->direita == raiz) {
                if (filho == raiz->direita)
                    return RightRight(raiz->pai);
                else if (filho == raiz->esquerda)
                    return RightLeft(raiz->pai);
            }
        }
    }

    return raiz;
}

void insertNoh ( pDescArvore arvore, void* info, FuncaoComparacao fcp) {
    if (FindBy(arvore, info, fcp) != NULL) {
        printf("Valor duplicado. Ignorando insercao.\n");
        return;
    }
    arvore->raiz = insertNohRecursivo(arvore->raiz, info, fcp);
    arvore->quantidade++;
}

//---------------------------- family ------------------------------

pNohArvore Irmao ( pNohArvore raiz ) {
    if(raiz == NULL)
        return NULL;


    if ( raiz->pai == NULL) {
        return NULL;
    }
    // Retorna o Irmao da raiz
    if(raiz->pai->esquerda == raiz) {
        return raiz->pai->direita;
    }
    else if ( raiz->pai->direita == raiz) {
        return raiz->pai->esquerda;
    }


    return NULL;

}
//------------------------------- Rotate --------------------------------------------

pNohArvore LeftLeft(pNohArvore p) {
    pNohArvore g = p->pai;

    // Recolorir
    p->cor = 1;
    g->cor = 0;

    // Rotacionar
    g->direita = p->esquerda;
    if (p->esquerda != NULL) {
        p->esquerda->pai = g;
    }
    p->esquerda = g;

    // Trocar pais
    p->pai = g->pai;
    g->pai = p;

    return p;
}

pNohArvore LeftRight(pNohArvore p) {
    p->direita = RightRight(p->direita);
    return LeftLeft(p);
}

pNohArvore RightRight(pNohArvore p) {
    pNohArvore g = p->pai;

    // Recolorir
    p->cor = 1;
    g->cor = 0;

    // Rotacionar
    g->esquerda = p->direita;
    if (p->direita != NULL) {
        p->direita->pai = g;
    }
    p->direita = g;

    // Trocar pais
    p->pai = g->pai;
    g->pai = p;

    return p;
}

pNohArvore RightLeft(pNohArvore p) {
    p->esquerda = LeftLeft(p->esquerda);
    return RightRight(p);
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

//---------------------------------- Remove ------------------------------------------

pNohArvore RemoveRecursivo(pNohArvore raiz, void* info, FuncaoComparacao fcp) {
    if ( fcp(info, raiz->info) > 0) {
        pNohArvore filho = RemoveRecursivo(raiz->direita, info, fcp);
        if ( raiz->pai == filho)
            return filho;
        else
            raiz->direita = filho;
    }
    else if ( fcp(info, raiz->info) < 0) {
        pNohArvore filho = RemoveRecursivo(raiz->esquerda, info, fcp);
        if ( raiz->pai == filho)
            return filho;
        else
        raiz->esquerda = filho;
    }
    else {
        if ( isLeaf(raiz) == 1) {
                //caso o nó seja folha
            if ( Irmao(raiz) == NULL) {
                    // caso o nó nao tenha irmao
                raiz->pai->cor = 1;

                freeNoh(raiz);
                return NULL;
            } else if ( isLeaf(Irmao(raiz)) == 1) {
                    //caso tenha irmao e que é folha
                Irmao(raiz)->cor = 0;

                freeNoh(raiz);

                return NULL;
            }else  {
                    //caso o noh tenha um irmao que nao seja folha
                pNohArvore b = Irmao(raiz); // b é irmao do noh
                pNohArvore p = raiz->pai; // p é pai do noh

                if ( b->direita != NULL && b->esquerda != NULL) {
                        // b tem 2 filhos

                    //rotaciona
                    if ( p->esquerda == raiz) {
                        p->esquerda = NULL;
                        p->direita  = b->esquerda;
                        b->esquerda = p;
                        p->direita->pai = p;
                        b->direita->cor = 1;
                        b->esquerda->cor = 0;
                    } else {
                        p->direita  =  NULL;
                        p->esquerda = b->direita;
                        b->direita  = p;
                        p->esquerda->pai = p;
                        b->esquerda->cor = 1;
                        b->direita->cor = 0;
                    }

                    //troca pais
                    b->pai = p->pai;
                    p->pai = b;

                    //recolorir
                    p->cor = 1;
                    b->cor = 1;

                    freeNoh(raiz);
                    return b;
                } else {
                        //irmao tem 1 filho
                   // if ( b->direita != NULL)
                        // o filho esta na direita
                   // else
                }

            }
        } else if ( raiz->direita != NULL && raiz->esquerda != NULL ) {
                //caso o nó tenha 2 filhos
            pNohArvore preNoh = PreNoh(raiz->esquerda);
            pNohArvore p = preNoh->pai;

            // Operacao para trocar a informação do nó que esta sendo removido pela sua mais proxima. depois excluir a mais proxima
            if (preNoh->pai == raiz) {
                    //caso o noh mais proximo seja logo à esquerda da raiz
                raiz->esquerda = preNoh->esquerda;

            }else {
                p->direita = NULL;
                p->direita = preNoh->esquerda;
            }
            if ( preNoh->esquerda != NULL  ) {
                preNoh->esquerda->pai = p;
            }
            free(raiz->info);
            raiz->info = preNoh->info;


            preNoh->info = NULL;
            freeNoh(preNoh);
            return raiz;

        } else {
                //caso tenha 1 filho
            pNohArvore filho;

            filho = raiz->direita != NULL ? raiz->direita : raiz->esquerda;

            raiz->info = filho->info;

            filho->pai = raiz->pai;
            filho->cor = 1;

            raiz->info = NULL;
            freeNoh(raiz);

            return filho;
        }
    }


}

int Remove(pDescArvore arvore, void* info, FuncaoComparacao fcp) {
    if ( FindBy(arvore, info, fcp) == NULL) {
        return 0;
    }else {
        arvore->raiz = RemoveRecursivo(arvore->raiz, info, fcp);
        arvore->quantidade--;
        return 1;
    }
}

int isLeaf(pNohArvore raiz) {
    if ( raiz->direita == NULL && raiz->esquerda == NULL ) {
        return 1;
    }else {
        return 0;
    }
}

pNohArvore PreNoh(pNohArvore raiz) {
    if ( raiz == NULL)
        return NULL;

    if(raiz->direita != NULL) {
        return PreNoh(raiz->direita);
    }
    return raiz;
}
