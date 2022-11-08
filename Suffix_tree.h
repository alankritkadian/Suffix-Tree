#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#include<stdio.h>
#define MAX 256
typedef struct SuffixTreeNode
{
   struct SuffixTreeNode *suffixLink;
   struct SuffixTreeNode *children[MAX];
   int suffixIndex;
   int *end ; 
   int start ; 
} node;
node* newNode(int start,int *end);
int edgeLength(struct SuffixTreeNode *a);
int walkDown(node *A);
void extendSuffixTree(int pos);
void print(int i, int j);
void buildSuffixTree(char* text);
void setSuffixIndex(node *n, int labelHeight);
node* returnRoot();
#endif


