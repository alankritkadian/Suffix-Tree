#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#define MAX 256

struct SuffixTreeNode{
   struct SuffixTreeNode *suffixLink;
   struct SuffixTreeNode *children[256];
   int suffixIndex;
   int *end ; 
   int start ; 
};
int activeLength;
int activeEdge;

int edgeLength(struct SuffixTreeNode*a);

#endif
