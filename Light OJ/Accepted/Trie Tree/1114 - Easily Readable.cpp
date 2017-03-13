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
    int next[52];
    Node()
    {
        memset(next, -1, sizeof(next));
    }
};

Node Trie[MAX];
int cnt[MAX];

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
    if(c>='a'&&c<='z') return c-'a';

    if(c>='A'&&c<='Z') return c-'A'+26;

    return 0;
}
int InsertTrie(char s[])
{
    int ptr=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(Trie[ptr].next[ind(s[i])]==-1)
        {
            Trie[ptr].next[ind(s[i])]=++kounter;
            ptr=kounter;
        }
        else
        {
            ptr=Trie[ptr].next[ind(s[i])];
        }
    }
    return ptr;
}

int Traverse_Tree(string s)
{
    int ptr=0;
    for(int i=0;i<s.size();i++)
    {
        if(Trie[ptr].next[ind(s[i])]==-1)
        {
            return -1;
        }
        else
        {
            ptr=Trie[ptr].next[ind(s[i])];
        }
    }
    return ptr;
}
int main()
{
    int test, kase=0, n, m;
    scanf("%d", &test);
    char str[128], sentence[10010];
    while(test--)
    {
        scanf("%d", &n);
        getchar();
        Initialize();
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            gets(str);
            int len = strlen(str);
            if(len>2) sort(&str[1], &str[1]+(len-2));
            int last = InsertTrie(str);
            cnt[last]++;
        }

        scanf("%d", &m);
        getchar();
        printf("Case %d:\n", ++kase);
        for(int i=0;i<m;i++)
        {
            gets(sentence);
            istringstream iss(sentence);
            string word;
            int ans=1;
            while(iss>>word)
            {
                int len=word.size();
                if(len>2)
                    sort(&word[1], &word[1]+(len-2));
                //cout<<word<<endl;
                int k = Traverse_Tree(word);
                if(k!=-1) ans = ans*cnt[k];
                else
                {
                    ans=0;
                    break;
                }
            }

            printf("%d\n", ans);
        }
    }
    return 0;

}
