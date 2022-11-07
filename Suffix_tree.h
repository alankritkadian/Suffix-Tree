#ifndef SUFFIX_TREE_H
#define SUFFIX_TREE_H
#define MAX 256
typedef struct SuffixTreeNode
{
   struct SuffixTreeNode *suffixLink;
   struct SuffixTreeNode *children[MAX];
   int suffixIndex;
   int *end ; 
   int start ; 
} node;

struct SuffixTreeNode *newNode(int start,int *end);
int edgeLength(struct SuffixTreeNode *a);
int walkDown(node *A);
void extendSuffixTree(int pos);
void buildSuffixTree();
void setSuffixIndex(node *n, int labelHeight);
#endif


