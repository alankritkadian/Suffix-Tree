#include <bits/stdc++.h>
using namespace std;

#define MAX 100 // maximum number of words in dictionary
#define TOL 2   // tolerance value
#define LEN 10  // maximum length of words in the dictionary

typedef struct BK_Tree_Node
{
    string word;
    int next[2 * LEN];
} node;

node rootNode;
node BK_Tree[MAX];
int ptr;

node createNode(string s)
{
    node n;
    n.word = s;
    for (int i = 0; i < 2 * LEN; i++)
        n.next[i] = 0;
    return n;
}

// Finding edit distance between two strings by dynamic approach
int editDistance(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] != s2[j - 1])
            {
                dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}

void addNode(node &rootNode, node &currentNode)
{
    if (rootNode.word == "")
    {
        rootNode = currentNode;
        return;
    }

    int d = editDistance(rootNode.word, currentNode.word);
    if (BK_Tree[rootNode.next[d]].word == "")
    {
        ptr++;
        BK_Tree[ptr] = currentNode;
        rootNode.next[d] = ptr;
    }
    else
        addNode(BK_Tree[rootNode.next[d]], currentNode);
}

vector<string> getSimilarWords(node &rootNode, string s)
{
    vector<string> similarWords;
    if (rootNode.word == "")
        return similarWords;

    int d = editDistance(rootNode.word, s);
    if (d <= TOL)
        similarWords.push_back(rootNode.word);

    int x = max(0, d - TOL);
    while (x <= d + TOL)
    {
        vector<string> temp = getSimilarWords(BK_Tree[rootNode.next[x]], s);
        for (int i = 0; i < temp.size(); i++)
            similarWords.push_back(temp[i]);
        x++;
    }
    return similarWords;
}

int main()
{
    string dictionary[] = {"hell", "help", "shell", "smell", "fell", "felt", "oops", "pop", "oouch", "halt", "harsh", "allenkrit", "llankrit", "alankarit"};
    ptr = 0;

    int n = sizeof(dictionary) / sizeof(string);

    for (int i = 0; i < n; i++)
    {
        node temp = createNode(dictionary[i]);
        addNode(rootNode, temp);
    }
    string w1 = "alankrit";
    string w2 = "helt";
    vector<string> match = getSimilarWords(rootNode, w1);
    cout << "similar words in dictionary for " << w1 << " :\n";
    for (auto x : match)
        cout << x << endl;
    return 0;
}