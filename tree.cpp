#include<bits/stdc++.h>

#define MAX 256
struct SuffixTreeNode{
   struct SuffixTreeNode *suffixLink;
   struct SuffixTreeNode *children[MAX];
   int suffixindex;
   int *end ; 
   int start ; 

};



int edgeLength(struct SuffixTreeNode*a)
{
  int e=*(a->end);
  int s= a->start ; 
  return (e-s+1);
}
int main(void){
  return 0;
}