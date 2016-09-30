#include<iostream>
#include<string.h>
#include<string>

using namespace std;
typedef unsigned long long LL;
#define Max 1000000000000000000LL

LL Factorial[50], n;
LL i;

void Generate_Factorial()
{
    Factorial[0]=1;
    Factorial[1]=1;

    for(i=2;;i++)
    {
        Factorial[i] = i*Factorial[i-1];

        if(Factorial[i]>=Max) break;
    }

    //for(int j=0;j<=i;j++)
        //cout<<Factorial[j]<<endl;
}


int main()
{
    Generate_Factorial();
    bool flag[21];

    int t, kase=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);

        memset(flag, 0, sizeof(flag));

        printf("Case %d: ", ++kase);


        for(int ptr=20;ptr>=0;ptr--)
        {
            if(n>=Factorial[ptr])
            {
                n = n-Factorial[ptr];
                flag[ptr]=true;
            }
        }
        bool k=false;
        if(n==0)
        {
            for(int ptr=0;ptr<20;ptr++)
            {
                if(flag[ptr]==true)
                {
                    if(k==false)
                    {
                        printf("%d!", ptr);
                        k=true;
                    }
                    else
                        printf("+%d!", ptr);
                }
            }
        }
        else printf("impossible");
        printf("\n");





    }
    return 0;
}
