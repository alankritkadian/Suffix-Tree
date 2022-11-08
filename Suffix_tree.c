#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Suffix_tree.h"
char *test;
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
void extendSuffixTree(int pos){
   END = pos;
   remainingSuffixCount++;
   lastNewNode = NULL;
   while(remainingSuffixCount){
      if(activeLength==0) activeEdge = pos;
      if(activeNode->children[test[activeEdge]]==NULL){
         activeNode->children[test[activeEdge]] = newNode(pos,&END);
         if(lastNewNode != NULL)
         {
            lastNewNode->suffixLink = activeNode;
            lastNewNode = NULL;
         }
      }else{
         node* next = activeNode->children[test[activeEdge]];
         if(walkDown(next))
         {
            continue;
         }
         if(test[next->start+activeLength]==test[pos]){
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
         activeNode->children[test[activeEdge]] = split;
         split->children[test[pos]] = newNode(pos,&END);
         next->start += activeLength;
         split->children[test[next->start]] = next;
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
void print(int i, int j)
{
	int k;
	for (k=i; k<=j; k++)
		printf("%c", test[k]);
}
void buildSuffixTree(char * text) {
   test = text;
   size = strlen(test);
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
	if (n == NULL) return;
	int leaf = 1;
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (n->children[i] != NULL)
		{
			leaf = 0;
			setSuffixIndex(n->children[i], labelHeight +
								edgeLength(n->children[i]));
		}
	}
	if (leaf == 1)
	{
		n->suffixIndex = size - labelHeight;
	}
}
node* returnRoot(){
   return root;
}