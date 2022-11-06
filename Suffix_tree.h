#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#define MAX 256
int count = 0;
struct node *root = NULL;
struct SuffixTreeNode
{
   struct SuffixTreeNode *suffixLink;
   struct SuffixTreeNode *children[256];
   int suffixIndex;
   int *end ; 
   int start ; 
};
int activeLength;
int activeEdge;

int edgeLength(struct SuffixTreeNode *a);
struct SuffixTreeNode *newNode(int start,int *end);
#endif