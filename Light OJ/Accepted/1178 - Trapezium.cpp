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

int main()
{
    double t1, t2, a, b, c, d, s1, s2, OB, OA, temp, OD, OC;
    int T;
    scanf("%d", &T);

    for(int kase=1;kase<=T;kase++)
    {
        cin>>a>>b>>c>>d;
        if(c>a)
        {
            temp=c;
            c=a;
            a=temp;
        }
        OA = d*c /(a-c);
        OB = b*c/(a-c);

        OD = OA + d;
        OC = OB + b;

        s1 = (OD + OC + a)/2;
        s2 = (OA + OB + c)/2;

        t1 = sqrt(s1*(s1-a)*(s1-OC)*(s1-OD));
        t2 = sqrt(s2*(s2-c)*(s2-OB)*(s2-OA));

        printf("Case %d: %lf\n", kase, t1-t2);



    }
}
