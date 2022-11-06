#include <stdio.h>
#include "Suffix_tree.h"

char text[100];
int count = 0;

int activeLength = 0;
int activeEdge = -1;

node *root = NULL;
node *lastNewNode = NULL;

node *activeNode = NULL;
int activeEdge = -1;
int activeLength = 0;

int remainingSuffixCount = 0;
int END = -1;
int *rootEnd = NULL;
int size;

node *newNode(int start, int *end)
{
   count++;
   node *STnode = (node *)malloc(sizeof(node));
   int r = 0;
   while (r < MAX)
      STnode->children[r++] = NULL;
   STnode->suffixLink = root;
   STnode->start = start;
   STnode->end = end;
   STnode->suffixIndex = -1;
   return STnode;
}

int edgeLength(node *A)
{
   long int e = *(A->end);
   long int s = A->start;
   return (e - s + 1);
}

int walkDown(node *A)
{
   // APCFWD - Active point change for walk down using skip/count trick(Trick 1)
   if (activeLength >= edgeLength(A))
   {
      activeNode = A;
      activeLength -= edgeLength(A);
      activeEdge = (int)text[activeEdge + edgeLength(A)] - (int)' ';
      return 1;
   }
   return 0;
}

void print(int i, int j)
{
   while (i <= j)
      printf("%c", text[i++]);
}

// Setting suffix indices for the suffix tree
void setSuffixIndex(node *n, int labelHeight)
{
   if (n == NULL) 
      return;
   for (int i = 0; i < MAX; i++)
   {
      if (n->children[i] != NULL)
         setSuffixIndex(n->children[i], labelHeight + edgeLength(n->children[i]));
   }
}