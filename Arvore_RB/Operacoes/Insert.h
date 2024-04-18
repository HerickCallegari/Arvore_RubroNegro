#include "StructArvore.h"

typedef int (*FuncaoComparacao) ( void*, void*);

typedef void (*FuncaoImpressao) ( void* );

pNohArvore tio ( pNohArvore raiz );

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

    if ( fcp(raiz->info, info) == 0 ) {
        return raiz;
    }


    pNohArvore filho;
    if ( fcp ( info, raiz->info ) > 0) {
        filho = insertNohRecursivo(raiz->direita, info, fcp);

        if ( raiz->pai != NULL && raiz->pai == filho ) {
            return filho;
        }else if (raiz->direita != NULL && raiz->direita->esquerda != NULL && raiz->pai == raiz->direita->esquerda) {
            return filho;
        }else {
        raiz->direita = filho;
        filho->pai = raiz;
        }

    }else if ( fcp ( info, raiz->info ) < 0) {
        filho = insertNohRecursivo(raiz->esquerda, info, fcp);
        if ( raiz->pai != NULL && raiz->pai == filho ) {
            return filho;
        }else if (raiz->esquerda != NULL && raiz->esquerda->direita != NULL && raiz->pai == raiz->esquerda->direita) {
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
            if ( raiz->pai->esquerda == raiz) {

                if (raiz->esquerda != NULL && raiz->esquerda->pai == raiz) {
                    return LeftLeft(raiz);
                }
                else if ( raiz->direita != NULL && raiz->direita->pai == raiz ) {
                    return LeftRight(raiz);
                }
            }
            else if ( raiz->pai->direita == raiz) {
                if ( raiz->direita != NULL && raiz->direita->pai == raiz ) {
                     return RightRight(raiz);
                }
                else if (raiz->esquerda != NULL && raiz->esquerda->pai == raiz) {
                    return RightLeft(raiz);
                }
            }

        }
    }

    return raiz;

}

void insertNoh ( pDescArvore arvore, void* info, FuncaoComparacao fcp) {
    if(FindBy(arvore, info, fcp) != NULL)
    printf("\nEste valor ja esta na arvore");
    else {
    arvore->raiz = insertNohRecursivo(arvore->raiz, info, fcp);
    arvore->quantidade++;
    }
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
