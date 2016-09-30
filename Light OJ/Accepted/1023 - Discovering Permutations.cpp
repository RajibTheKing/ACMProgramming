#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int N, K, kount;
int A[100];

void perm(int ind)
{
    int i, j;
    if(ind==N&&kount<K)
    {
        kount++;

        for(int k=0;k<N;k++)
            printf("%c", A[k]+'A'-1);
        cout<<endl;

        return;
    }
    for(i=1;i<=N;i++)
    {
        int check = 1;
        for(j=0;j<ind;j++)
        {
            if(A[j]==i)
                check=0;

        }
        if(check)
        {
            A[ind]=i;
            if(kount<K)
                perm(ind+1);
        }
    }

}
int main()
{
    int T, kase=0;
    cin>>T;
    while(T--)
    {
        memset(A, 0, sizeof(A));
        cin>>N>>K;
        kount=0;
        printf("Case %d:\n", ++kase);
        perm(0);
    }
    return 0;
}
