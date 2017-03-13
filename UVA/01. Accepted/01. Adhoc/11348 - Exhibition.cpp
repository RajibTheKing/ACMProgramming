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

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


int data[55][55];
int sz[55];
int itemNum[10100];
int ans[55];
double realAns[55];

int main()
{
    int T, N, M, kase=0;
    cin>>T;
    while(T--)
    {
        cin>>N;
        memset(itemNum, 0, sizeof(itemNum));

        for(int i=0;i<N;i++)
        {
            int temp=0;
            cin>>sz[i];
            for(int j=0;j<sz[i];j++)
            {
                cin>>data[i][j];
                bool flag=true;
                for(int k=0;k<j;k++)
                {
                    if(data[i][k]==data[i][j])
                        flag=false;
                }

                if(flag)
                {
                    itemNum[data[i][j]]++;
                    temp++;
                }
            }
            //cout<<"Here: "<<temp<<endl;

        }
        memset(ans, 0, sizeof(ans));
        double sum=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<sz[i];j++)
            {
                bool flag=true;
                for(int k=0;k<j;k++)
                {
                    if(data[i][k]==data[i][j])
                        flag=false;
                }

                if(flag&&itemNum[data[i][j]]==1)
                {
                    //cout<<"Item: "<<data[i][j]<<", Num = "<<itemNum[data[i][j]]<<endl;
                    ans[i]++;
                }
            }
            //cout<<"Unique item: "<<ans[i]<<endl;
            sum+=ans[i];
        }
        //cout<<"Sum: "<<sum<<endl;
        csprnt;
        for(int i=0;i<N;i++)
        {
            realAns[i] = (ans[i]*100.0)/(sum*1.0);
            if(i) printf(" ");
            printf("%0.6lf%%", realAns[i]);

        }
        printf("\n");

    }

    return 0;
}

