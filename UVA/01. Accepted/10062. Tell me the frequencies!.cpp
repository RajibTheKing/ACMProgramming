#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
typedef long long LL;
typedef struct Node
{
    int item;
    int kount;
    bool flag;
};

Node A[130];

bool compare(Node p, Node q)
{
    if(p.kount==q.kount)
    {
        if(p.item>q.item) return true;
        else
            return false;
    }
    else
    {
        if(p.kount<q.kount) return true;
        else
            return false;
    }


}

char c[10000];

int main()
{
    string s;
    //while(getline(cin, s))

    bool K = true;
    while(gets(c))
    {
        if(K!=true) cout<<endl;

        memset(A, 0, sizeof(A));
        s="";
        for(int i=0;i<strlen(c);i++)
            s+=c[i];

        for(int i=0;i<s.length();i++)
        {
            A[s[i]].kount++;
            A[s[i]].flag=true;
            A[s[i]].item = s[i];
        }
        sort(&A[0], &A[128], compare);

        for(int i=0;i<129;i++)
        {
            if(A[i].flag)
                cout<<A[i].item<<" "<<A[i].kount<<endl;
        }
        memset(c, 0, sizeof(c));
        K=false;

    }
    //cout<<"F \r R";
}



