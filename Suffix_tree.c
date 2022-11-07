#include <stdio.h>
#include "Suffix_tree.h"

char text[100];

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
int *splitEnd = NULL;
int size = -1;
node *newNode(int start, int *end)
{
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
   if(A==root)
      return 0;
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
      activeEdge += edgeLength(A);
      return 1;
   }
   return 0;
}
// Setting suffix indices for the suffix tree
void extendSuffixTree(int pos){
   END = pos;
   remainingSuffixCount++;
   lastNewNode = NULL;
   while(remainingSuffixCount){
      if(activeLength==0) activeEdge = pos;
      if(activeNode->children[text[activeEdge]]==NULL){
         activeNode->children[text[activeEdge]] = newNode(pos,&END);
         if(lastNewNode != NULL)
         {
            lastNewNode->suffixLink = activeNode;
            lastNewNode = NULL;
         }
      }else{
         node* next = activeNode->children[text[activeEdge]];
         if(walkDown(next))
         {
            continue;
         }
         if(text[next->start+activeLength]==text[pos]){
            if(lastNewNode != NULL && activeNode != root)
            {
               lastNewNode->suffixLink = activeNode;
               lastNewNode = NULL;
            }
            activeLength++;
            break;
         }
         splitEnd = (int*)malloc(sizeof(int));
         *splitEnd = next->start + activeLength - 1;
         node* split = newNode(next->start,splitEnd);
         activeNode->children[text[activeEdge]] = split;
         split->children[text[pos]] = newNode(pos,&END);
         next->start += activeLength;
         split->children[text[next->start]] = next;
         if(lastNewNode!=NULL){
            lastNewNode->suffixLink = split;
         }
         lastNewNode = split;
      }
      remainingSuffixCount--;
      if(activeNode==root&&activeLength>0){
         activeLength--;
         activeEdge = pos - remainingSuffixCount + 1;
      }else if(activeNode != root){
         activeNode = activeNode->suffixLink;
      }
   }
}
void buildSuffixTree() {
   size = strlen(text);
   rootEnd = (int*) malloc(sizeof(int));
   *rootEnd = -1;
   root = newNode(-1,rootEnd);
   activeNode = root;
   int j = 0;
   while(j<size)
      extendSuffixTree(j++);
   int labelHeight = 0;
   setSuffixIndex(root,labelHeight);
}
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