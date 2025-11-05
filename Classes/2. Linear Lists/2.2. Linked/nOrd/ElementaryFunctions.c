#include <stdio.h>

typedef struct Node
{
  int E;
  Node* Next;
} Node;

void Insert (Node* L, int x)
{
  // For non ordered linked lists
  // Complexity... time: tetha(1) ; memory: tetha(1)

  Node* tmp;
  tmp = (Node*) malloc(sizeof(Node));
  tmp->E = x; tmp->Next = L;
  L = tmp;
  free(tmp);
}

Node* Search (Node* L, int x)
{
  // For non ordered linked lists
  // Complexity... time: tetha(N) ; memory: tetha(1)

  Node* p = L;
  while (p != NULL)
  {
    if (p->E == x)
    {
      return p;
    }
    else
    {
      p = p->Next;
    }
  }
  return NULL; // Here I could return p once it would be NULL, but I wanted it clear on code
}

void Remove (Node* L, int x)
{
  // For non ordered linked lists
  // Complexity... time: tetha(N) ; memory: tetha(1)
  
  Node *p, *pBefore;
  p = L; pBefore = NULL;

  while (p != NULL)
  {
    if (p->E == x)
    {
      if (pBefore == NULL)
      {
        L = p->Next; free(p); p = L;
      }
      else
      {
        pBefore->Next = p->Next; free(p); p = pBefore->Next;
      }
    }

    pBefore = p; p = p->Next;
  }
}