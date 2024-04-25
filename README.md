
# Descricao do projeto
 * Trabalho na matéria estrutura de dados, objetivo: Criar uma biblioteca em C de uma arvore de pesquisa binaria balanceada do tipo rubro-negra.
# Demonstração
#### Estrutura Descritor
* A estrutura padrão da arvore consiste em um descritor, que contem a informação da quantidade de nós presentes na arvore e uma "raiz" que seria o nó inicial desta arvore:

```
typedef struct DescritorArvoreRB descArvore;
typedef descArvore* pDescArvore;

struct DescritorArvoreRB {
    pNohArvore raiz;
    int quantidade;
};
```
#### Estrutura Noh
* As "raizes" ou "nós" ou "Noh", são formados pela seguinte estrutura:
```
typedef struct DescritorArvoreRB descArvore;
typedef descArvore* pDescArvore;

struct NohArvoreRB{
    void* info;
    pNohArvore direita;
    pNohArvore esquerda;
    pNohArvore pai;
    int cor; // vermelho = 0 | preto = 1
};
```
* Onde "direita" e "esquerda" são nohs que aponta para outros nohs, que segue a mesma estrutura, o noh "pai" aponta para o noh que antecede o noh em questão e "cor" é um numero inteiro que tem respresentação boelana, onde 0 representa "Vermelho" e 1 representa "Preto"


## Funções da Biblioteca
* Função para instanciar o descritor:

  Cabeçalho:
  ```
  pDescArvore criarArvore();
  ```
  Exemplo:
  ```
  pDescArvore Descritor;

  Descritor = criarArvore();
  ```
* Função de insert:

  Cabeçalho:
  ```
  void insertNoh(pDescArvore arvore, void *info, FuncaoComparacao pfc);
  ```
  Exemplo:
  ```
  insertNoh(Descritor, alocaInt(5), compInt);
  ```
* Função de FindBy:

  Cabeçalho:
  ```
  pNohArvore FindBy(pDescArvore arvore, void* info, FuncaoComparacao fcp);
  ```
  Exemplo:
  ```
  pNohArvore FindBy(Descritor, alocaInt(5), compInt);
  ```
* Função de Print:

  Cabeçalho:
  ```
  void DesenhaArvore(pDescArvore arvore, FuncaoImpressao fi)
  ```
  Exemplo:
  ```
  DesenhaArvore(desc, printaInt);
  ```
  Resultado:
  
* Função de remove:

  Cabeçalho:
  ```
  int Remove(pDescArvore arvore, void* info, FuncaoComparacao fcp)
  ```
  

