#include <stdio.h>

typedef struct Node
{
  int E;
  Node* Next;
} Node;

void Insert (Node* L, int x)
{
  // For ordered linked lists
  // Complexity... time: O(N) ; memory: tetha(1)

  Node *p, *pBefore, *newNode;
  p = L; pBefore = NULL;

  while ( (p != NULL) && (p->E < x) )
  {
    pBefore = p; p = p->Next;
  }

  newNode = (Node*) malloc (sizeof(Node)); newNode->E; newNode->Next = NULL;

  if (pBefore == NULL)
  {
    newNode->Next = L; L = newNode;
  }
  else
  {
    newNode->Next = p; pBefore->Next = newNode;
  }
}

Node* Search (Node* L, int x)
{
  // For ordered linked lists
  // Complexity... time: O(N) ; memory: tetha(1)

  Node* p = L;

  while ( (p != NULL) && (p->E < x) )
  {
    if (p->E == x)
    {
      return p;
    }

    p = p->Next;
  }

  return NULL;
}

void Remove (Node* L, int x)
{
  // For ordered linked lists
  // Complexity... time: O(N) ; memory: tetha(1)


  Node *p, *pBefore;
  p = L; pBefore = NULL;

  while ( (p != NULL) && (p->E < x) )
  {
    pBefore = p; p = p->Next;
  }

  while ( (p != NULL) && (p->E == x) )
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
}