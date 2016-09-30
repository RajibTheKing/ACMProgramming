#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
#include<string.h>
#include<stdio.h>

using namespace std;
#define MAX 100000
struct Node
{
    int next[11];
    Node()
    {
        memset(next, -1, sizeof(next));
    }
};

Node Trie[MAX];
bool ans;
int kounter;

void Initialize()
{
    kounter=0;
    for(int i=0;i<MAX;i++)
    {
        Trie[i]=Node();
    }
}
int ind(char c)
{
    return c-'0';
}
void InsertTrie(string s)
{
    bool flag=false;
    int ptr=0;
    for(int i=0;i<s.size();i++)
    {
        if(Trie[ptr].next[ind(s[i])]==-1)
        {
            Trie[ptr].next[ind(s[i])]=++kounter;
            ptr=kounter;
            flag=true;
        }
        else
        {
            ptr=Trie[ptr].next[ind(s[i])];
        }
    }

    if(flag==false)
        ans=false;
}

bool cmp(string a, string b)
{
    if(a.size()>b.size()) return true;
    return false;
}
int main()
{
    int test, kase=0, n, m;
    scanf("%d", &test);
    char str[128];
    string SS[10010];
    while(test--)
    {
        scanf("%d", &n);
        getchar();
        Initialize();

        for(int i=0;i<n;i++)
        {
            gets(str);
            istringstream iss(str);
            SS[i]=str;
        }
        sort(SS, SS+n, cmp);
        ans = true;
        for(int i=0;i<n;i++)
        {
            InsertTrie(SS[i]);
            if(ans==false) break;
        }

        printf("Case %d: ", ++kase);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;

}
