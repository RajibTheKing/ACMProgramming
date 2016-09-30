#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000001
char S[N],W[N];
int T[N];
int len1,len2;

void getNext()
{
    int j=0,k=-1;
    T[0]=-1;
    len2=strlen(W);
    while(j<len2)
    {
        if(k==-1||W[j]==W[k])
        {
            j++;
            k++;
            if(W[j]!=W[k])
                T[j]=k;
            else
                T[j]=T[k];
        }
        else
            k=T[k];
    }
//    for(int i=0;i<len2;i++)
//        cout<<T[i]<<" ";
//    cout<<endl;
}
int KMP_Search()
{
    getNext();
    int i=0,j=0,ans=0;
    len1=strlen(S);
    while(i<len1)
    {
        if(j==-1||S[i]==W[j])
        {
            i++;
            j++;
            if(j>=len2)
            {
                j=T[j];
                ans++;
            }
        }
        else
            j=T[j];
    }
    return ans;
}
int main()
{
    int t,c=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%s %s",S,W);
        printf("Case %d: %d\n",++c,KMP_Search());
    }
    return 0;
}
