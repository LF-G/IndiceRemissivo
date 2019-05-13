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



/* ////////// Defini��es de structs e tipos de dados //////////*/


struct no {
    char *palavra;
    celula *p;
    struct no *esq;
    struct no *dir;
};
typedef struct no noh;
typedef noh *arvore;



/*///////////  Fun��es  //////////////////////////////////////*/


/* Recebe uma palavra palvr e uma �rvore de busca r. Devolve um
n� que cont�m a palavra palvr. Se tal n� n�o existe, devolve
NULL.                                                         */

noh *buscaNo (arvore r, char *palvr);


/* Recebe o endere�o eer do endere�o de uma �rvore de busca e 
uma folha avulsa novo. Insere a folha no lugar correto da �rvore
e atualiza *eer de modo que esse seja  o endere�o da �rvore 
resultante.                                                   */

void insereNo (arvore *eer, noh *novo);


/* Esta fun��o imprime no arquivo arq o conte�do de um �nico n�
x da �rvore.                                                  */

void imprimeNo (FILE *arq, noh *x);


/* Recebe uma �rvore bin�ria de busca r e libera todo o espa�o
utilizado para armazen�-la.                                   */

void liberaArvore (arvore r);


/* Recebe uma �rvore bin�ria r e retorna a quantidade de n�s 
contidos na �rvore.                                           */

int contaNos (arvore r);


/* Devolve a altura da �rvore bin�ria cuja raiz � r.          */

int altura (arvore r);


#endif

