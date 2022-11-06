#include<stdio.h>
#include"Suffix_tree.h"
int edgeLength(struct SuffixTreeNode*a)
{
  int e=*(a->end);
  int s= a->start ; 
  return (e-s+1);
}