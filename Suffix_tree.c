#include<stdio.h>
#include"Suffix_tree.h"
long int edgeLength(struct SuffixTreeNode*a)
{
  long int e=*(a->end);
  long int s= a->start ; 
  return (e-s+1);
}
struct SuffixTreeNode *newNode(long int start, int *end)
{
   count = count + 1;
   struct SuffixTreeNode *STnode = (struct SuffixTreeNode *)malloc(sizeof(struct SuffixTreeNode));
   long int r = 0;
   while (r < MAX)
   {
      STnode->children[r] = NULL;
      r++;
   }
   STnode->suffixLink = root;
   STnode->start = start;
   STnode->end = end;
   STnode->suffixIndex = -1;
   return STnode;
}
