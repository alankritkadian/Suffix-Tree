#include<bits/stdc++.h>
#include<string.h>
#include"Suffix_tree.h"
#include"PatternSearch.h"
using namespace std;
int main(void)
{
    string s;
    FILE* filepointer;
    filepointer = fopen("Items.txt","r");
    char temp[50];
    while(!feof(filepointer)){
        fgets(temp,50,filepointer);
        // cout<<temp<<endl;
        s = s + temp;
    }
    cout<<"Welcome to the grocery Store!\nPlease choose\n-1 for consumer end\n-2 for seller end\n";
    int x;cin>>x;
    int z = s.size();
    char Text[z];
    for(int i=0;i<z;i++) Text[i] = s[i];
    buildSuffixTree(Text);
    if(x==1){
    }else if(x==2){
        cout<<"Please enter the item you want to search: ";
        cin>>temp;
        node* root = returnRoot();
        checkForSubString(temp,root,Text);
        // cout<<s<<endl;
    }
    return 0;
}