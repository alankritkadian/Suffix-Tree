#include<stdio.h>
#include<string.h>
#include"Suffix_tree.h"
#include"PatternSearch.h"
int main(void)
{
    char text[100];
    strcpy(text, "GEEKSFORGEEKS$"); 
    buildSuffixTree();    
    printf("Text: GEEKSFORGEEKS, Pattern to search: GEEKS");
    node* root = returnRoot();
    char test[100];
    strcpy(test, "GEEKS"); 
    checkForSubString(test,root,text);
    return 0;
}