#ifndef STRUCTARVORE_H
#define STRUCTARVORE_H


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

#endif
