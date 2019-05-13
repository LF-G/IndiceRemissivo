/////////////////////////////////////////////////////////////////
//  
// Autor: Luiz Fernando Galati                                                 
//                                                            
///////////////////////////////////////////////////////////////*/



#ifndef _ARVORE_H
#define _ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"



/* ////////// Definições de structs e tipos de dados //////////*/


struct no {
    char *palavra;
    celula *p;
    struct no *esq;
    struct no *dir;
};
typedef struct no noh;
typedef noh *arvore;



/*///////////  Funções  //////////////////////////////////////*/


/* Recebe uma palavra palvr e uma árvore de busca r. Devolve um
nó que contém a palavra palvr. Se tal nó não existe, devolve
NULL.                                                         */

noh *buscaNo (arvore r, char *palvr);


/* Recebe o endereço eer do endereço de uma árvore de busca e 
uma folha avulsa novo. Insere a folha no lugar correto da árvore
e atualiza *eer de modo que esse seja  o endereço da árvore 
resultante.                                                   */

void insereNo (arvore *eer, noh *novo);


/* Esta função imprime no arquivo arq o conteúdo de um único nó
x da árvore.                                                  */

void imprimeNo (FILE *arq, noh *x);


/* Recebe uma árvore binária de busca r e libera todo o espaço
utilizado para armazená-la.                                   */

void liberaArvore (arvore r);


/* Recebe uma árvore binária r e retorna a quantidade de nós 
contidos na árvore.                                           */

int contaNos (arvore r);


/* Devolve a altura da árvore binária cuja raiz é r.          */

int altura (arvore r);


#endif

