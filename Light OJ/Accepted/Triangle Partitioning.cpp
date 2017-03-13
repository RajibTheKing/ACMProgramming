#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
main()
{
    int T;
    double a, b, c, AB, BC, AC, t, m, ADE, s,sinT, AD ;
    cin>>T;
    int kase= 0;

    while(T--)
    {
        cin>>AB>>BC>>AC>>m;
        s = AB + BC + AC;
        s = s/2;
        t = sqrt(s*(s-AB)*(s-BC) * (s-AC));


        ADE = (m * t)/(1+m);


        sinT = (2*t)/(BC*AB);
        AD = sqrt((2 * AB * ADE)/(BC * sinT));

        printf("Case %d: %lf\n", ++kase, AD);




    }

}

