#include"Suffix_tree.h"
#include<stdio.h>
int traverseEdge(char *str, int idx, int start, int end,char* text)
{
    int k = 0;
    for(k=start; k<=end && str[idx] != '\0'; k++, idx++)
    {
        if(text[k] != str[idx])
            return -1; 
    }
    if(str[idx] == '\0')
        return 1;  
    return 0;  
}
int doTraversalToCountLeaf(node *n)
{
    if(n == NULL)
        return 0;
    if(n->suffixIndex > -1)
    {
        printf("\nFound at position: %d", n->suffixIndex);
        return 1;
    }
    int count = 0;
    int i = 0;
    for (i = 0; i < MAX; i++)
    {
        if(n->children[i] != NULL)
        {
            count += doTraversalToCountLeaf(n->children[i]);
        }
    }
    return count;
}
  
int countLeaf(node *n)
{
    if(n == NULL)
        return 0;
    return doTraversalToCountLeaf(n);
}
  
int doTraversal(node *n, char* str, int idx,char* text)
{
    if(n == NULL)
    {
        return -1;
    }
    int res = -1;
    if(n->start != -1)
    {
        res = traverseEdge(str, idx, n->start, *(n->end),text);
        if(res == -1)
            return -1;
        if(res == 1) 
        {
            if(n->suffixIndex > -1)
                printf("\nsubstring count: 1 and position: %d",
                               n->suffixIndex);
            else
                printf("\nsubstring count: %d", countLeaf(n));
            return 1;
        }
    }
    idx = idx + edgeLength(n);
    if(n->children[str[idx]] != NULL)
        return doTraversal(n->children[str[idx]], str, idx,text);
    else
        return -1;  // no match
}
  
void checkForSubString(char* str,node* root,char* text)
{
    int res = doTraversal(root, str, 0,text);
    if(res == 1)
        printf("\nPattern <%s> is a Substring\n", str);
    else
        printf("\nPattern <%s> is NOT a Substring\n", str);
}