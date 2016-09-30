#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;

double x,y,d,c,r;

void Calculate(double x1,double x2,double x3,double y1,double y2,double y3)
{
     double c1,c2;
     c1=0.5*((x1*x1-x2*x2)+(y1*y1-y2*y2));
     c2=0.5*((x1*x1-x3*x3)+(y1*y1-y3*y3));
     d=(x1-x2)*(y1-y3)-(x1-x3)*(y1-y2);
     x=c1*(y1-y3)-c2*(y1-y2);
     y=c2*(x1-x2)-c1*(x1-x3);
     x/=d;
     y/=d;
     r=(x1-x)*(x1-x)+(y1-y)*(y1-y);
     r=sqrt(r);
     //c=-(x1*x1)-(y1*y1)+2*x*x1+2*y*y1;
     c = x*x + y*y - r*r;
}

void output1(void)
{
     printf("(x ");
     (x>0)?printf("- "):printf("+ ");
     printf("%.3lf)^2 + (y ",fabs(x));
     (y>0)?printf("- "):printf("+ ");
     printf("%.3lf)^2 = ",fabs(y));
     printf("%.3lf^2\n",r);
}

void output2(void)
{
     printf("x^2 + y^2 ");
     (x>0)?printf("- "):printf("+ ");
     printf("%.3lfx ",fabs(2*x));
     (y>0)?printf("- "):printf("+ ");
     printf("%.3lfy ",fabs(2*y));
     (c>0)?printf("+ "):printf("- ");
     printf("%.3lf = 0\n",fabs(c));
}

int main()
{
     double x1,x2,x3,y1,y2,y3;

     while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
     {
	   Calculate(x1,x2,x3,y1,y2,y3);


	   output1();
	   output2();
	   printf("\n");
     }

     return 0;
}
