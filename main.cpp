#include <bits/stdc++.h>
#include <string.h>
#include "Suffix_tree.h"
#include "PatternSearch.h"
#include "bloom.hpp"
#include "BK_Tree.hpp"
using namespace std;
int main(void)
{
    vector<string> Items;
    bool bitarray[1000] = {false};
    int arrSize = 1000;
    int pos[100];
    BkNode* RootNode;
    string s1 = "";
    cout << "Welcome to the grocery Store!\n";
    label:
    cout<<"Please choose\n-1 for consumer end\n-2 for seller end\n-3 exit\n";
    int x;
    cin >> x;
    if (x == 1)
    {
        string name, item = "";
        cout << "Please enter your name: ";
        cin >> name;
        int l = name.length();
        cout << "Enter items you want(enter \"end\" when you're done): ";
        while (item != "end")
        {
            cin >> item;
            if (item != "end")
            {
                RootNode = ReturnBNode();
                vector<string> match = getSimilarWords(*RootNode, item);
                int found = 0;
                for (auto x : match)
                    if(x==item) found = 1;
                if(!found&&!match.empty()){
                    cout<<"It seems you mispelled.\nEnter the Index of the one you want from following Items:\n";
                    for (auto x : match)
                        cout<<x<<endl;
                    int index;cin>>index;
                    item = match[index-1];
                }else if(match.empty()){
                    cout<<"No such item or closely spelled item found.\n";
                }   
                if(!match.empty()){             
                    s1.append(name + to_string(l));
                    s1.append(item);
                }
            }
        }
        cout << "Thank you " << name << '!' << endl;
        // cout << s1 << endl;
        goto label;
    }
    else if (x == 2)
    {
        cout << "Please choose an operation:\n-1 for Updating Item\n-2 for Searching Item\n";
        int op2;
        cin >> op2;
        if (op2 == 1)
        {
            string s2;
            cout << "PLease enter the Item name: ";
            cin >> s2;
            if (insert(bitarray, arrSize, s2))
            {
                Items.push_back(s2);
                BkNode NodeOp2 = createNode(Items.at(Items.size()-1));
                RootNode = ReturnBNode();
                addNode(*RootNode,NodeOp2);
            }
        }
        else if (op2 == 2)
        {
            s1 += "$";
            int z = s1.size();
            char Text[z];  
            char temp[50];
            for (int i = 0; i < z; i++)
                Text[i] = s1[i];
            buildSuffixTree(Text); 
            cout<<"-1 To display Reciept\n-2 To Search\n";
            int h;cin>>h;
            string hero;
            if(h==2){
                cout<<"Enter the Item to be Searched: ";
                cin>>hero;
            }
            for(auto x:Items){
                if(h==2) x = hero;
                int y = 0; 
                z = x.length();
                char Temp2[z+1];
                for(int i=0;i<z;i++) Temp2[i] = x[i]; 
                Temp2[z] = '\0';           
                SNode *root = returnRoot();
                checkForSubString(Temp2, root, Text,pos);
                cout<<"\nThe Following have ordered "<<x<<": ";
                while(pos[y]!=-1){
                    // cout<<Text[pos[y]-1]<<" ";
                    int num = Text[pos[y]-1]-48;
                    int num2 = Text[pos[y]-2]-48;
                    // cout<<num<<" "<<num2<<" ";
                    int found = 0;
                    if(num2>=0&&num2<=9){
                        found = 1;
                        num = 10*(Text[pos[y]-2]-48)+(Text[pos[y]-1]-48);
                    }
                    // cout<<num<<" ";
                    for(int g = pos[y]-1-found-num;g<pos[y]-1-found;g++){
                        cout<<Text[g];
                    }
                    cout<<" ";
                    y++;
                }
                cout<<endl;
                cout<<"------\n\n";
                if(h==2) break;
            }
            s1.pop_back();
            // pos[0] = -1;
        }
        goto label;
    }
    return 0;
}