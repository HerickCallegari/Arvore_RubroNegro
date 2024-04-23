#include "utils.h"

#define ESPACO 5

// ############################### Conexoes ###############################

#include "Operacoes/StructArvore.h"

#include "Operacoes/CriarDescritor.h"

#include "Operacoes/ProcuraNoh.h"

#include "Operacoes/ImprimeArvore.h"

#include "Operacoes/Insert.h"

#include "Operacoes/Remove.h"

// ############################### Cabeçalhos ###############################

typedef int (*FuncaoComparacao) ( void*, void*);

typedef void (*FuncaoImpressao) ( void* );

pNohArvore Right ( pNohArvore raiz);

pNohArvore RightLeft(pNohArvore raiz);

pNohArvore Left(pNohArvore raiz);

pNohArvore LeftRight(pNohArvore raiz);

int isLeaf(pNohArvore raiz);

pNohArvore PreNoh(pNohArvore raiz);


// ############################### implementações ###############################

