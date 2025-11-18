#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Espaço na versão lista sequencial int F[N -1]: está sendo um ponteiro para cada inteiro
// Espaço na versão lista encadeada No* F: o espaço dos  

#define LIN 100
#define COL 100
#define N LIN*COL

/*typedef enum Tipo
{


} ;*/

/*struct Formula 
{
  int F[N-1];


  } ;*/

/*typedef union Tipo
{
  int val;
  struct Formula int F[N-1];
} ;*/


typedef struct No
{
  int E;
  No * prox;
} No;

typedef struct Celula
{
  char tipo; // Tipo da célula (ex: 'n' <- numérica)
  bool vazia;
  bool atualizada;
  int val;
//  int F[N-1]; // Ler o primeiro comentário feito nesse arquivo
  No * F;
  int nF;
} Celula;


void DefVal (Celula P[], int i, int v)
{
  P[i].vazia = false;
  P[i].tipo = 'n';
  P[i].val = v;
}


void InsereNo (No * &L, int x)
{
  No * n = (No *) malloc(sizeof(No));
  n->E = x;
  n->prox = L;
  L = n;
}

void DefFor (Celula P[], int i, int v[], int nv)
{
  P[i].tipo = 'f';
  P[i].vazia = false; // ?
  P[i].F = NULL; // ?


  for (int j=0; j < nv; j++)
  {
    InsereNo(P[i].F, v[j]);
  }
}


void SomaValF (Celula P[])
{
  // Soma os valores da fórmula apontada por F

  


}


void AtualizaValores (Celula P[], int i, char tipo)
{
  int nf = 0;
  for (int i=0; i<N; i++)
  {
    P[i].atualizada = (P[i].tipo == 'n'); // se é um valor, então já está atualizado
    nf += (P[i].atualizada ? 0 : 1); // número de fórmulas
  }

  while (nf > 0)
  {
    for (int i=0; i<N; i++)
    {
      if (! P[i].atualizada) // Se não está atualizada, então é uma fórmula
      {

      }
    }
  }

}


void ExibePlanilha (Celula P[])
{
  for (int i = 0; i < N; i++)
  {
    if (! P[i].vazia)
    {
      printf(" P[%d]: %d\n", i+1, P[i].val);
    }
  }

}


void ConstroiPlanilha (Celula P[])
{
  for (int i = 0; i < N; i++)
  {
    P[i].vazia = 1;

    // Inicializar todos os valores como 0
  
  }
}


void DestroiPlanilha (Celula P[])
{
  free(P);
}


int main (void)
{
//  Celula P[N]; // Se fosse contruir na pilha de execução (pouco espaço para um programa desse tipo)
  Celula * P = (Celula *)  malloc(sizeof(int) * N);
  ConstroiPlanilha(P);
  
  DefVal(P, 2, 2);
  DefVal(P, 7, 10);
  DefVal(P, 15, 10);
  DefVal(P, 16, 1);
  DefVal(P, 22, 5);
  DefVal(P, 25, 3);
  DefVal(P, 28, 4);

  ExibePlanilha(P);

  DestroiPlanilha(P);

  return 0;
}