#ifndef BIBLIOTECA_ARVORE_RUBRO_NEGRA_H
#define BIBLIOTECA_ARVORE_RUBRO_NEGRA_H
#include "utils.h"

#define ESPACO 5

// ############################### Cabeçalhos ###############################

typedef int (*FuncaoComparacao) ( void*, void*);

typedef void (*FuncaoImpressao) ( void* );

pNohArvore Right ( pNohArvore raiz);

pNohArvore RightLeft(pNohArvore raiz);

pNohArvore Left(pNohArvore raiz);

pNohArvore LeftRight(pNohArvore raiz);

int isLeaf(pNohArvore raiz);

pNohArvore PreNoh(pNohArvore raiz);

pNohArvore avo(pNohArvore raiz);

pNohArvore tio(pNohArvore raiz);
// ############################### Conexoes ###############################

#include "Operacoes/StructArvore.h"

#include "Operacoes/CriarDescritor.h"

#include "Operacoes/ProcuraNoh.h"

#include "Operacoes/ImprimeArvore.h"

#include "Operacoes/Insert.h"

#include "Operacoes/Remove.h"

#include "Operacoes/Rotacoes.h"

#include "Operacoes/Remove.h"



#endif
