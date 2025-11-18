#include <stdio.h>
#include <stdlib.h>


// Structures

typedef struct Node
{
  int E;
  struct Node* Next;
} Node;


// Functions assignment
void Insert (Node** L, int x);
Node* Search (Node* L, int x);
void Remove (Node** L, int x);
void ShowLinked (Node * L);




int main (void)
{
  Node * L = NULL;
  printf("Current list: "); ShowLinked(L);

  Insert(&L, 1); printf("\nInserting 1 inside the list...\n\n");
  printf("New list: "); ShowLinked(L);
  
  Insert(&L, 8); printf("\nInserting 8 inside the list...\n\n");
  printf("New list: "); ShowLinked(L);
  
  Insert(&L, 101); printf("\nInserting 101 inside the list...\n\n");
  printf("New list: "); ShowLinked(L);

  Insert(&L, 12); printf("\nInserting 12 inside the list...\n\n");
  printf("New list: "); ShowLinked(L);

  puts("");

  printf("Is there 8 inside the list? %d\n", !Search(L, 8) == 0);
  printf("Is there 80 inside the list? %d\n", !Search(L, 80) == 0);

  puts("");

  Remove(&L, 8); printf("Removing 8 from the list...\n\n");
  printf("New list: "); ShowLinked(L);
  printf("\nIs there 8 inside the list? %d\n", !Search(L, 8) == 0);

  return 0;
}




void Insert (Node** L, int x)
{
  // For ordered linked lists
  // Complexity... time: O(N) ; memory: tetha(1)

  Node *p, *pBef, *newNode;
  newNode = (Node*) malloc (sizeof(Node)); newNode->E = x; newNode->Next = NULL;
  p = *L; pBef = NULL;

  while ( (p != NULL) && (p->E < x) )
  {
    pBef = p; p = p->Next;
  }

  if (pBef == NULL)
  {
    newNode->Next = *L; *L = newNode;
  }
  else
  {
    newNode->Next = p; pBef->Next = newNode;
  }
}

Node* Search (Node* L, int x)
{
  // For ordered linked lists
  // Complexity... time: O(N) ; memory: tetha(1)

  Node* p = L;

  while ( (p != NULL) && (p->E <= x) )
  {
    if (p->E == x)
    {
      return p;
    }

    p = p->Next;
  }

  return NULL;
}

void Remove (Node** L, int x)
{
  // For ordered linked lists
  // Complexity... time: O(N) ; memory: tetha(1)


  Node *p, *pBefore;
  p = *L; pBefore = NULL;

  while ( (p != NULL) && (p->E < x) )
  {
    pBefore = p; p = p->Next;
  }

  while ( (p != NULL) && (p->E == x) )
  {
    if (pBefore == NULL)
    {
      *L = p->Next; free(p); p = *L;
    }
    else
    {
      pBefore->Next = p->Next; free(p); p = pBefore->Next;
    }
  }
}

void ShowLinked (Node * L)
{
  if(!L) printf("NULL\n");
  for (Node * p = L; p != NULL; p = p->Next)
  {
    printf("%d", p->E);
    if (p->Next != NULL) printf(" -> ");
    else printf(" -> NULL\n");
  }
}