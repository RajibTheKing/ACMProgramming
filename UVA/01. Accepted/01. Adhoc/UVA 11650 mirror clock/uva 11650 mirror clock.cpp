#include<iostream>
#include<stdio.h>
using namespace std;

int outH[30][65], outM[30][65];


void PreCalculation(void)
{
    int h1, h2, m1, m2;
    for(h1=12, m1=0, h2=12, m2=0;  h1>=4; )
    {
        outH[h1][m1]=h2;
        outM[h1][m1]=m2;

        outH[h2][m2]=h1;
        outM[h2][m2]=m1;
        //cout<<h1<<":"<<m1<<" = "<<outH[h1]<<":"<<outM[m1]<<endl;

        m1--; m2++;

        if(m1==-1)
        {
            h1--;
            m1=59;
        }
        if(m2==60)
        {
            h2++;
            m2=0;
        }
        if(h2==13)
            h2=1;
    }
}

int main()
{
    //freopen("output.txt", "w", stdout);
    PreCalculation();

    int T, h, m;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d:%d", &h, &m);
        //cout<<"          ans = ";
        printf("%02d:%02d\n", outH[h][m], outM[h][m]);
    }

    return 0;
}
