#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H

#include "../Arvore_RB.h"

/* ---------------------------------------------------------------------*/
pNohArvore InsertNohRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    // caso base
    if (raiz == NULL){
       raiz = malloc(sizeof(NohArvore));
       raiz->info     = info;
       raiz->esquerda = NULL;
       raiz->direita  = NULL;
       raiz->cor      = 0;
       return raiz;
    }
    else{
       pNohArvore filho;
       /* caso recursivo */
       if (pfc(info, raiz->info) >= 0){
           filho = InsertNohRecursivo(raiz->esquerda, info, pfc);
           if (filho->direita == raiz){
               // houve rotação a direita, não precisa alterar o filho esquerda,
               // somente ajusta a raiz para apontar para o filho
               raiz = filho;
           } else {
               filho->pai     = raiz;
               raiz->esquerda = filho;
           }

        }
        else {
           filho = InsertNohRecursivo(raiz->direita, info, pfc);
           if (filho->esquerda == raiz){
               // houve rotação a esquerda, não precisa alterar o filho esquerda,
               // somente ajusta a raiz para apontar para o filho
               raiz = filho;
           } else {
               filho->pai    = raiz;
               raiz->direita = filho;
           }
        }

        if (raiz->pai == NULL){
            // é a raiz da árvore, tem que ser 1
            raiz->cor = 1;
            return raiz;
        }

        // verifica a cor do pai
        if (raiz->cor == 1 ||
            (raiz->cor == 0 && filho->cor == 1)){
            // não precisa fazer nada, não tem como violar alguma das regras
             return raiz;
        }

         // ----------------------------------------------
        // caso 1: verifica se ambos o pai e o tio são 0,
        //         muda a cor de ambos para 1 e a cor do
        //         avô para 0
        // ----------------------------------------------
        if (raiz->cor == 0 && corTio(filho) == 0){

             raiz->cor       = 1;
             tio(filho)->cor = 1;
             if (avo(filho) != NULL){
                 avo(filho)->cor = 0;
             }

             return raiz;
          }

          // ----------------------------------------------
          // Caso 2: pai e tio com cores diferentes
                // São 4 possibilidades:
          if (raiz->cor == 0 && corTio(filho) != 0){

              pNohArvore novaRaiz;

              if (raiz->esquerda == filho && raiz->pai->esquerda == raiz) {
                  // caso 2.1 - Left-Left
                  novaRaiz = Right(filho);

              } else if (raiz->direita == filho && raiz->pai->esquerda == raiz){
                        // caso 2.2 - Left-direita
                        novaRaiz = LeftRight(filho);

              } else if (raiz->direita == filho && raiz->pai->direita == raiz){
                        // caso 2.3 - direita-direita
                        novaRaiz = Left(filho);

              } else if (raiz->esquerda == filho && raiz->pai->direita == raiz){
                        // caso 2.4 - Left-direita
                        novaRaiz = RightLeft(filho);
              }
              return novaRaiz;
            }
    }
    return raiz;
}

/* ----------------------------------------------------------*/
void InsertNoh(pDescArvore arvore, void *info, FuncaoComparacao pfc){
    arvore->raiz = InsertNohRecursivo(arvore->raiz, info, pfc);
    arvore->raiz->cor = 1;
    arvore->quantidade++;
}

#endif

