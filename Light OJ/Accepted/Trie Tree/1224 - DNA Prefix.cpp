#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;
#define MAX 2500000
typedef struct Node
{
    int next[4];
    bool isEndingNode;
    int passTime;
};

Node Trie[MAX];
int kounter;
map<char, int> mp;
int maxx;

void Initialize()
{
    mp.clear();
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;

    kounter=0;
    for(int i=0;i<MAX;i++)
    {
        for(int k=0;k<4;k++)
        {
            Trie[i].next[k]=-1;
            Trie[i].isEndingNode=false;
            Trie[i].passTime=0;
        }
    }
}
int ind(char c)
{
    return mp[c];
}
void InsertTrie(char s[])
{
    int ptr=0;
    Trie[ptr].passTime++;
    for(int i=0;i<strlen(s);i++)
    {
        if(Trie[ptr].next[ind(s[i])]==-1)
        {

            Trie[ptr].next[ind(s[i])]=++kounter;
            ptr=kounter;
            Trie[ptr].passTime++;

        }
        else
        {
            ptr=Trie[ptr].next[ind(s[i])];
            Trie[ptr].passTime++;
        }
        maxx = max(maxx, (i+1)*Trie[ptr].passTime);
    }
    Trie[ptr].isEndingNode=true;
}

int main()
{


    int test, kase=0, n;
    scanf("%d", &test);
    char str[55];
    while(test--)
    {
        scanf("%d", &n);
        getchar();
        Initialize();
        maxx=0;
        for(int i=0;i<n;i++)
        {
            gets(str);
            InsertTrie(str);
        }
        printf("Case %d: %d\n", ++kase, maxx);
//        memset(dp, -1, sizeof(dp));
//        rec(0);
//        maxx=0;
//        FindSolution(0,0);
//        printf("Case %d: %d\n", ++kase, maxx);

    }
    return 0;

}
