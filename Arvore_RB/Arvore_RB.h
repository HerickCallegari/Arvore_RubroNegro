#include "utils.h"

#define ESPACO 5

// ############################### Conexoes ###############################

#include "Operacoes/StructArvore.h"

#include "Operacoes/CriarDescritor.h"

#include "Operacoes/ProcuraNoh.h"

#include "Operacoes/Rotacoes.h"

#include "Operacoes/ImprimeArvore.h"

#include "Operacoes/Insert.h"

// ############################### Cabeçalhos ###############################

typedef int (*FuncaoComparacao) ( void*, void*);

typedef void (*FuncaoImpressao) ( void* );

pNohArvore LeftLeft ( pNohArvore p);

pNohArvore LeftRight(pNohArvore p);

pNohArvore RightRight(pNohArvore p);

pNohArvore RightLeft(pNohArvore p);

int isLeaf(pNohArvore raiz);

pNohArvore PreNoh(pNohArvore raiz);


// ############################### implementações ###############################

