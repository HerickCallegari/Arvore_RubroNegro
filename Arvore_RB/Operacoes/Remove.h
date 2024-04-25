#ifndef REMOVE_INFO_ARVORE_BINARIA_H
#define REMOVE_INFO_ARVORE_BINARIA_H

#include "../Arvore_RB.h"

pNohArvore minValueNode(pNohArvore raiz) {
    pNohArvore minVal = raiz;

    // Percorre a �rvore at� encontrar o n� mais � esquerda
    while (minVal != NULL && minVal->esquerda != NULL) {
        minVal = minVal->esquerda;
    }

    return minVal;
}

pNohArvore RemoveInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        return raiz;
    }

    if (pfc(info, raiz->info) < 0) {
        raiz->esquerda = RemoveInfoRecursivo(raiz->esquerda, info, pfc);
    } else if (pfc(info, raiz->info) > 0) {
        raiz->direita = RemoveInfoRecursivo(raiz->direita, info, pfc);
    } else {
        // Este � o n� a ser exclu�do
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            pNohArvore filho = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (filho == NULL) {
                // Nenhum filho
                filho = raiz;
                raiz = NULL;
            } else {
                // Um filho
                *raiz = *filho;
            }
            free(filho);
        } else {
            // Dois filhos: obtenha o sucessor (menor chave na sub�rvore direita)
            pNohArvore filho = minValueNode(raiz->direita);
            raiz->info = filho->info;
            raiz->direita = RemoveInfoRecursivo(raiz->direita, filho->info, pfc);
        }
    }

    if (raiz == NULL)
        return raiz;

    // Chamadas para fun��es de ajuste p�s-exclus�o espec�ficas da �rvore rubro-negra
    // balanceAfterDeletion(raiz);

    return raiz;
}

int RemoveInfo(pDescArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 0;
    }
    arvore->raiz = RemoveInfoRecursivo(arvore->raiz, info, pfc);
    return 1;
}

#endif
