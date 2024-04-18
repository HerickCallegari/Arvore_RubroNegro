#include "Operacoes/StructArvore.h"
int compInt ( void* info1, void* info2) {
     int* inteiro1 = (int*)info1;
    int* inteiro2 = (int*)info2;

    return *inteiro1 - *inteiro2;
}

void printaInt(void* info) {
    printf("%d", *(int*)info);
}

int* alocaInt(int n) {
    int *pi = (int *) malloc(sizeof(int));
   *pi = n;
   return pi;
}

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
