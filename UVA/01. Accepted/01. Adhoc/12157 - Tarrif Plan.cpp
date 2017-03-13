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


int MileCost(int num)
{
    int sum = 0;
    int rate = 10;
    for(int i=0;i<=num;i+=30)
    {
        sum+=rate;
        //rate+=10;
    }
    //cout<<"Mile: "<<num<<" "<<sum<<endl;
    return sum;
}
int JuiceCost(int num)
{
    int sum = 0;
    int rate = 15;
    for(int i=0;i<=num;i+=60)
    {
        sum+=rate;
       // rate+=15;
    }
    //cout<<"Juice: "<<num<<" "<<sum<<endl;
    return sum;

}

int main()
{
    int T, n, temp, kase=0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &temp);
            sum1+=MileCost(temp);
            sum2+=JuiceCost(temp);
        }
        csprnt;
        if(sum1==sum2)
            printf("Mile Juice %d\n", sum1);
        else if(sum1<sum2)
            printf("Mile %d\n", sum1);
        else
            printf("Juice %d\n", sum2);





    }

    return 0;
}
