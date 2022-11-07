#ifndef PATTERN_SEARCH_H
#include"Suffix_tree.h"
#define PATTERN_SEARCH_H
#define MAX 256
int traverseEdge(char *str, int idx, int start, int end,char* text);
int doTraversalToCountLeaf(node *n);
int countLeaf(node *n);
int doTraversal(node *n, char* str, int idx,char* text);
void checkForSubString(char* str,node* root,char* text);
#endif
