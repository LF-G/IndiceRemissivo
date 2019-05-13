//////////////////////////////////////////////////////////////////  
//                                                               
// Autor: Luiz Fernando Galati                                                    
//                                                               
///////////////////////////////////////////////////////////////*/



/*///////////  Interfaces de bibliotecas  /////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "arvore.h"
#include "lista.h"



/*////////////////  Protótipos de funções  ////////////////////*/

FILE *fopenn (const char *filename, const char *mode);
char *expandePalavra (char *palvr, int Epalvr);
int ehBoa (char *palvr);
arvore constroiIndice (FILE *arq);
void imprimeIndice (FILE *arq, arvore r);
int pisoLog2 (int N);



/*///////////  Funções   //////////////////////////////////////*/


int main (int numargs, char *arg[])
{    
    FILE *entrada, *saida;
    arvore r;
    int n, h, pisoLog;
    double start, finish, elapsed, ms;
        
    entrada = fopenn (arg[1], "r");
    start = (double) clock () / CLOCKS_PER_SEC;
    r = constroiIndice (entrada);
    finish = (double) clock () / CLOCKS_PER_SEC;
    elapsed = finish - start;
    ms = elapsed*1000;
    n = contaNos (r);
    pisoLog = pisoLog2 (n);
    h = altura (r);
    printf ("\n");
    printf ("Tempo gasto na construcao do indice    | %.2f ms         \n", ms);
    printf ("--------------------------------------- -----------------\n");
    printf ("Numero n de nos da arvore              | %d              \n", n);
    printf ("--------------------------------------- -----------------\n");
    printf ("pisoLog2 (n)                           | %d              \n", pisoLog);
    printf ("--------------------------------------- -----------------\n");
    printf ("Altura da arvore                       | %d              \n", h);
    printf ("\n");
    saida = fopenn (arg[2], "w");
    imprimeIndice (saida, r);
    liberaArvore (r);
    fclose (entrada);
    fclose (saida);
    
    return EXIT_SUCCESS;
}


/* Esta função recebe um número inteiro nbytes, aloca os nbytes na
memória e devolve o endereço do conjunto de bytes alocado. Foi 
criada para evitar a repetição da verificação de erro 
(ponteiro == NULL) ao longo das outras funções do programa.      */ 

void *mallocc (size_t nbytes)
{
    void *ptr;
    ptr = malloc (nbytes);
    if (ptr == NULL) {
        printf ("Erro!\n");
        exit (EXIT_FAILURE);
    }
    return ptr;
}


/* Recebe uma string filename e uma string mode. Abre o arquivo 
de nome filename no modo descrito pela string mode e retorna um
ponteiro para o arquivo aberto.
   Esta função é uma adaptação da função fopen da biblioteca
padrão e foi criada para evitar a repetição da verificação de
erro (ponteiro == NULL) ao longo das outras funções do programa.  */

FILE *fopenn (const char *filename, const char *mode)
{
    FILE *arq;
    arq = fopen (filename, mode);
    if (arq == NULL) {
        printf ("Erro na abertura de arquivos.\n");
        exit (EXIT_FAILURE);
    }
    return arq;
}


/* Recebe uma string palvr e o tamanho Epalvr do vetor alocado para
abrigar essa string. Devolve a string palvr alocada num vetor de
tamanho Epalvr*2.                                                 */

char *expandePalavra (char *palvr, int Epalvr)
{
    char *novaPalvr;
    novaPalvr = mallocc ((Epalvr * 2) * sizeof (char));
    strcpy (novaPalvr, palvr);
    free (palvr);
    return novaPalvr;
}


/* Recebe uma palavra palvr. Devolve 1 se ela for considerada boa
(ou seja, se começar com uma letra minúscula) e 0 caso contrário. */

int ehBoa (char *palvr)
{
    if (islower (palvr[0]))
        return 1;
    return 0;
}


/* Esta função retorna uma árvore binária de busca que contém o
índice remissivo do arquivo arq.                                  */                                                          

arvore constroiIndice (FILE *arq)
{
    int i, Epalvr, nlinha;
    char c;
    char *palvr;
    arvore r;
    noh *novo, *x;
    celula *p;
    
    r = NULL;
    nlinha = 1;
    Epalvr = 5;     
    palvr = mallocc ((Epalvr) * sizeof (char));    
    c = getc (arq);      
    while (c != EOF) {
        i = 0;
        while (isalnum (c)) {            
            palvr[i] = c;
            if (palvr[i] >= 'A' && palvr[i] <= 'Z')
                palvr[i] = tolower (palvr[i]);
            i++;
            if (i == Epalvr) {
                palvr = expandePalavra (palvr, Epalvr);
                Epalvr *= 2;          
            }
            c = getc (arq);
        }
        palvr[i] = '\0';
        x = buscaNo (r, palvr);  
        if (ehBoa (palvr) && i > 2) {
            if (x == NULL) {
                novo = mallocc (sizeof (noh));
                novo->palavra = mallocc ((i + 1) * sizeof (char));
                strcpy (novo->palavra, palvr);
                novo->p = insereCel (nlinha, novo->p);
                novo->esq = novo->dir = NULL;            
                insereNo (&r, novo);
            }
            else {
                p = buscaCel (nlinha, x->p);
                if (p == NULL)
                    x->p = insereCel (nlinha, x->p);                
            }
        }
        if (c == '\n')
            nlinha++;        
        if (c != EOF)
            c = getc (arq);
    }    
    free (palvr);    
    return r;    
}


/* Esta função imprime no arquivo arq o índice remissivo contido na
árvore de busca r.                                                 */

void imprimeIndice (FILE *arq, arvore r)
{
    if (r != NULL) {
        imprimeIndice (arq, r->esq);
        imprimeNo (arq, r);        
        imprimeIndice (arq, r->dir);
    }
}


/* Esta função recebe um inteiro N > 0 e devolve o valor do piso do
logaritmo de N na base 2.                                          */

int pisoLog2 (int N)
{  
    int i, n;
    i = 0;
    n = N;
    while (n > 1) {
        n = n/2;
        i += 1;
    }
    return i;    
}

