#include <bits/stdc++.h>
#include <string.h>
#include "Suffix_tree.h"
#include "PatternSearch.h"
#include "bloom.hpp"
using namespace std;
int main(void)
{
    string s;
    FILE *filepointer;
    filepointer = fopen("Order.txt", "r");
    char temp[50];
    while (!feof(filepointer))
    {
        fgets(temp, 50, filepointer);
        // cout<<temp<<endl;
        s = s + temp;
    }
    fclose(filepointer);
    vector<string> Items;
    bool bitarray[1000] = {false};
    int arrSize = 1000;
    int z = s.size();
    char Text[z];  
    for (int i = 0; i < z; i++)
        Text[i] = s[i];
    buildSuffixTree(Text);  
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
                s1.append(name + to_string(l));
                s1.append(item);
            }
        }
        cout << "Thank you " << name << '!' << endl;
        cout << s1 << endl;
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
            cout << "PLease eneter the Item name: ";
            cin >> s2;
            if (insert(bitarray, arrSize, s2))
            {
                Items.push_back(s2);
            }
        }
        else if (op2 == 2)
        {
            cout << "Please enter the item you want to search: ";
            cin >> temp;
            SNode *root = returnRoot();
            checkForSubString(temp, root, Text);
        }
        goto label;
    }
    return 0;
}