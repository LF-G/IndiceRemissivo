//////////////////////////////////////////////////////////////////  
//                                                               
// Autor: Luiz Fernando Galati                                                    
//                                                               
///////////////////////////////////////////////////////////////*/



/*///////////  Interfaces de bibliotecas  /////////////////////*/

#include "arvore.h"



/*///////////  Prot�tipos de fun��es  /////////////////////////*/

noh *buscaNo (arvore r, char *palvr);
void insereNo (arvore *eer, noh *novo);
void imprimeNo (FILE *arq, noh *x);
static arvore removeraiz (arvore r);
void liberaArvore (arvore r);
int contaNos (arvore r);
int altura (arvore r);



/*///////////  Fun��es  //////////////////////////////////////*/


/* Veja a documenta��o no arquivo interface arvore.h          */

noh *buscaNo (arvore r, char *palvr)
{
    if (r == NULL || strcmp (r->palavra, palvr) == 0)
        return r;
    if (strcmp (r->palavra, palvr) > 0)
        return buscaNo (r->esq, palvr);
    else
        return buscaNo (r->dir, palvr);
}


/* Veja a documenta��o no arquivo interface arvore.h          */

void insereNo (arvore *eer, noh *novo)
{  
    noh *pai;
    pai = NULL;
    while (*eer != NULL) {
        pai = *eer;
        if (strcmp (pai->palavra, novo->palavra) > 0)
            eer = &(pai->esq);
        else
            eer = &(pai->dir);
    } 
    *eer = novo;
}


/* Veja a documenta��o no arquivo interface arvore.h          */

void imprimeNo (FILE *arq, noh *x)
{
    celula *p;
    fprintf (arq, "%s  ", x->palavra);
    for (p = x->p; p != NULL; p = p->prox) {
        fprintf (arq, "%d", p->linha);
        if (p->prox != NULL)
            fprintf (arq, ", ");
    }
    fprintf (arq, "\n");
}


/* Recebe uma �rvore n�o vazia r. Remove a raiz da �rvore e
rearranja-a de modo que ela continue sendo de busca. Devolve o
endere�o da nova raiz.                                        */

static arvore removeraiz (arvore r)
{  
    noh *p, *q;
    if (r->esq == NULL) {
        q = r->dir;
        free (r);
        return q;
    }
    p = r; q = r->esq;
    while (q->dir != NULL) {
        p = q; q = q->dir;
    }
    if (p != r) {
        p->dir = q->esq;
        q->esq = r->esq;
    }
    q->dir = r->dir;
    free (r);
    return q;
}


/* Veja a documenta��o no arquivo interface arvore.h         */

void liberaArvore (arvore r)
{
    while (r != NULL) {
        liberaLista (r->p);       
        r = removeraiz (r);
    }
}


/* Veja a documenta��o no arquivo interface arvore.h         */

int contaNos (arvore r)
{
    if (r == NULL)
        return 0;
    return 1 + contaNos (r->esq) + contaNos (r->dir);
}


/* Veja a documenta��o no arquivo interface arvore.h         */

int altura (arvore r)
{
    if (r == NULL) 
        return -1;
    else {
        int he = altura (r->esq);
        int hd = altura (r->dir);
        if (he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

