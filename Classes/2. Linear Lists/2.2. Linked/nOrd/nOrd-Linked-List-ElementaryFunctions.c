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
  // For non ordered linked lists
  // Complexity... time: tetha(1) ; memory: tetha(1)

  Node* newNode = (Node*) malloc(sizeof(Node)); newNode->E = x; newNode->Next = *L;
  *L = newNode;
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
  return NULL; // Here I could return p, once it would be also NULL, but I wanted it clear on code
}

void Remove (Node** L, int x)
{
  // For non ordered linked lists
  // Complexity... time: tetha(N) ; memory: tetha(1)
  
  Node *p, *pBefore;
  p = *L; pBefore = NULL;

  while (p != NULL)
  {
    if (p->E == x)
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

    pBefore = p; p = p->Next;
  }
}

void ShowLinked (Node * L)
{
	Node *p = L;

  if (p) // Testing if it is a null list
    {
    while (p != NULL)
    {
      printf("%d", p->E);

      if (p->Next != NULL)
      {
        printf(" -> ");
      }
      else
      {
        printf(" -> NULL\n");
      }

      p = p->Next;
    }
  }
  else
  {
    printf("NULL\n");
  }
}