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

priority_queue<int> GQ, BQ, gq, bq;


bool hasSoldiar()
{
    if(!GQ.empty() && !BQ.empty()) return true;
    return false;
}
void ClearAllQueue()
{
    while(!GQ.empty())GQ.pop();
    while(!BQ.empty())BQ.pop();
    while(!gq.empty())gq.pop();
    while(!bq.empty())bq.pop();
}
int main()
{
    int T, B, SG, SB, val, s1, s2;
    scanf("%d", &T);
    bool flag=false;
    while(T--)
    {
        ClearAllQueue();
        if(flag) printf("\n");
        flag=true;
        scanf("%d %d %d", &B, &SG, &SB);
        for(int i=0;i<SG;i++)
        {
            scanf("%d", &val);
            GQ.push(val);
        }
        for(int i=0;i<SB;i++)
        {
            scanf("%d", &val);
            BQ.push(val);
        }

        //int rounds=0;
        while(hasSoldiar())
        {
            //cout<<"Round: "<< ++rounds<<endl;
            for(int i=0;i<B && hasSoldiar();i++)
            {

                s1 = GQ.top(); GQ.pop();
                s2 = BQ.top(); BQ.pop();
                //cout<<s1<<" "<<s2<<endl;
                if(s1>s2) gq.push(s1-s2);
                if(s1<s2) bq.push(s2-s1);
            }
            while(!gq.empty())
            {
                GQ.push(gq.top());
                gq.pop();
            }
            while(!bq.empty())
            {
                BQ.push(bq.top());
                bq.pop();
            }
        }

        if(GQ.empty()==true&&BQ.empty()==true)
        {
            printf("green and blue died\n");
        }
        else if(GQ.empty()==true)
        {
            printf("blue wins\n");
            while(!BQ.empty())
            {
                printf("%d\n", BQ.top());
                BQ.pop();
            }
        }
        else
        {
            printf("green wins\n");
            while(!GQ.empty())
            {
                printf("%d\n", GQ.top());
                GQ.pop();
            }
        }

    }


    return 0;
}
