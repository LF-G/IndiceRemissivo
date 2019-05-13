//////////////////////////////////////////////////////////////////  
//                                                               
// Autor: Luiz Fernando Galati                                                    
//                                                               
///////////////////////////////////////////////////////////////*/



/*///////////  Interfaces de bibliotecas  /////////////////////*/

#include "lista.h"



/*///////////  Prot�tipos de fun��es  /////////////////////////*/

static void *malloc_c (size_t nbytes);
celula *buscaCel (int x, celula *ini);
celula *insereCel (int x, celula *ini);
void liberaLista (celula *ini);



/*///////////  Fun��es  //////////////////////////////////////*/


/* Esta fun��o recebe um n�mero inteiro nbytes, aloca os nbytes
na mem�ria e devolve o endere�o do conjunto de bytes alocado.
Foi criada para evitar a repeti��o da verifica��o de erro
(ponteiro == NULL) ao longo das outras fun��es do m�dulo.     */

static void *malloc_c (size_t nbytes)
{
    void *ptr;
    ptr = malloc (nbytes);
    if (ptr == NULL) {
       printf ("Erro!\n");
       exit (EXIT_FAILURE);
    }
    return ptr;
}


/* Veja a documenta��o no arquivo interface lista.h           */

celula *buscaCel (int x, celula *ini)
{
    celula *p;
    p = ini;
    while (p != NULL && p->linha != x) 
        p = p->prox; 
    return p; 
}


/* Veja a documenta��o no arquivo interface lista.h           */

celula *insereCel (int x, celula *ini)
{
    celula *nova, *p;

    nova = malloc_c (sizeof (celula));
    nova->linha = x;
    nova->prox = NULL;
    if (ini == NULL)
        return nova;
    for (p = ini; p->prox != NULL; p = p->prox);
    p->prox = nova;
    return ini;      
}


/* Veja a documenta��o no arquivo interface lista.h           */

void liberaLista (celula *ini)
{
    celula *p, *q;
    p = ini;
    q = ini->prox;
    while (q != NULL) {
        free (p);
        p = q;
        q = q->prox;
    }
    free (p);
    p = NULL;
}

