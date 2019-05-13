//////////////////////////////////////////////////////////////////  
//                                                               
// Autor: Luiz Fernando Galati                                                    
//                                                               
///////////////////////////////////////////////////////////////*/



#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>



/* ////////// Definições de structs e tipos de dados //////////*/


struct cel {
    int linha;
    struct cel *prox;
};
typedef struct cel celula;



/*///////////  Funções  //////////////////////////////////////*/


/* Esta função recebe um inteiro x e uma lista encadeada ini de
inteiros, sem célula-cabeça. Devolve o endereço de uma celula 
que contém x ou devolve NULL se tal célula não existe.        */ 

celula *buscaCel (int x, celula *ini);


/* Esta função insere uma nova célula de conteúdo x no fim de
uma lista encadeada sem cabeça ini. Devolve o endereço da lista
resultante.                                                   */

celula *insereCel (int x, celula *ini);


/* Esta função recebe uma lista ligada sem cabeça ini e libera
todo o espaço alocado para armazená-la.                       */

void liberaLista (celula *ini);


#endif

