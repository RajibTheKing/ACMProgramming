#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

vector<int>factor[1005];
vector<int>prime;
bool flag[1200];

void sieve(void)
{
    int i, j, k;
    flag[0]=true;flag[1]=true;

    for(i=2;i<=1100;i++)
    {
        if(flag[i]==0)
        {
            prime.push_back(i);
            for(j=i+i;j<=1100;j+=i)
                flag[j]=1;
        }
        if(prime.size()>170) break;
    }

}


void factorize(void)
{
    sieve();
    int num, item;
    int i, j, k;
    for(num=2; num<=1000; num++)
    {
        item = num;

        for(i=0;item!=1;)
        {
            if(flag[num]==false) break;
            else if(item%prime[i]==0)
            {
                k=factor[num].size();
                if(k==0)
                      factor[num].push_back(prime[i]);
                else if(factor[num][k-1]!=prime[i])
                    factor[num].push_back(prime[i]);
                item=item/prime[i];
            }
            else i++;
        }
    }
}

int BFS(int s, int t)
{
    if(s==t) return 0;

    queue<int>Q;
    queue<int>R;
    vector<int>save;
    save.clear();
    bool check[5000];
    memset(check, false, sizeof(check));
    bool f=false;
    Q.push(s);
    R.push(0);
    int A, B, x, len, temp;

    while(!Q.empty())
    {
        A = Q.front(); Q.pop();
        len = R.front(); R.pop();
        for(int i=0;i<factor[A].size();i++)
        {
            x=factor[A][i];
            temp=A+x;
            //printf("temp = %d, x = %d, len = %d\n", temp, x, len+1);
            if(check[temp]==false)
            {
                if(temp<t)
                {
                    Q.push(temp);
                    R.push(len+1);

                }
                if(temp==t)
                {
                    f=true;
                    save.push_back(len+1);
                }

                check[temp]=true;
            }

        }
    }
    if(f==false) return -1;

    int min = 99999;

    for(int i=0;i<save.size();i++)
        if(save[i]<min) min=save[i];

    return min;


}

int main()
{
    factorize();
    int  s, t, n,ans, kase=0;

    while(cin>>s>>t)
    {
        if(s==0&&t==0) break;

        ans = BFS(s, t);

        printf("Case %d: %d\n", ++kase, ans);

    }
}
