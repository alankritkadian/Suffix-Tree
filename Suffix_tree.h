#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#define MAX 50

struct SuffixTreeNode{
   struct SuffixTreeNode *suffixLink;
   struct SuffixTreeNode *children[256];
   int suffixindex;
   int *end ; 
   int start ; 

};

int edgeLength(struct SuffixTreeNode*a);

#endif
