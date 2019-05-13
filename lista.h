//////////////////////////////////////////////////////////////////  
//                                                               
// Autor: Luiz Fernando Galati                                                    
//                                                               
///////////////////////////////////////////////////////////////*/



#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>



/* ////////// Defini��es de structs e tipos de dados //////////*/


struct cel {
    int linha;
    struct cel *prox;
};
typedef struct cel celula;



/*///////////  Fun��es  //////////////////////////////////////*/


/* Esta fun��o recebe um inteiro x e uma lista encadeada ini de
inteiros, sem c�lula-cabe�a. Devolve o endere�o de uma celula 
que cont�m x ou devolve NULL se tal c�lula n�o existe.        */ 

celula *buscaCel (int x, celula *ini);


/* Esta fun��o insere uma nova c�lula de conte�do x no fim de
uma lista encadeada sem cabe�a ini. Devolve o endere�o da lista
resultante.                                                   */

celula *insereCel (int x, celula *ini);


/* Esta fun��o recebe uma lista ligada sem cabe�a ini e libera
todo o espa�o alocado para armazen�-la.                       */

void liberaLista (celula *ini);


#endif

