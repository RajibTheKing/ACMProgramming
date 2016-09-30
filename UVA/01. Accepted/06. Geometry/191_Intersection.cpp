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

int A1, A2, B1, B2, C1, C2;
int fuck=0;
void Construct_General_Format(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    A1=y2-y1;
    B1=x1-x2;
    C1=A1*x1+B1*y1;

    A2=y4-y3;
    B2=x3-x4;
    C2=A2*x3+B2*y3;
}
bool Checking_Intersection(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    double det = A1*B2 - A2*B1;
    if(det==0)
    {
        //cout<<"Parallel"<<endl;
        if(y1==y2&&y2==y3&&y3==y4)
        {
            if(min(x3, x4)<=x1&&x1<=max(x3, x4))
                return true;
            else if(min(x3, x4)<=x2&&x2<=max(x3, x4))
                return true;
            else return false;
        }
        else
        {
            if(min(y3, y4)<=y1&&y1<=max(y3, y4))
                return true;
            else if(min(y3, y4)<=y2&&y2<=max(y3, y4))
                return true;
            else return false;
        }


    }
    else
    {
        double x = (B2*C1-B1*C2)/det;
        double y = (A1*C2-A2*C1)/det;
        //cout<<x<<", "<<y<<endl;
        if(min(x1, x2)<=x&&x<=max(x1, x2)&&min(y1, y2)<=y&&y<=max(y1, y2)&&min(x3, x4)<=x&&x<=max(x3, x4)&&min(y3, y4)<=y&&y<=max(y3, y4))
            return true;
        else
        {
            //cout<<"false "<<fuck<<endl;
            return false;
        }
    }
}
bool inside_the_rectangle(int x1, int y1, int x2, int y2, int xleft, int ytop, int xright, int ybottom)
{
    if(min(xleft, xright)<=x1&&x1<=max(xleft, xright)&&min(ybottom, ytop)<=y1&&y1<=max(ybottom, ytop))
        return true;
    else if(min(xleft, xright)<=x2&&x2<=max(xleft, xright)&&min(ybottom, ytop)<=y2&&y2<=max(ybottom, ytop))
        return true;
    else
    {
        //cout<<"false "<<fuck<<endl;
        return false;

    }

}
int main()
{
    int Test, kase=0;
    int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
    scanf("%d", &Test);
    getchar();

    while(Test--)
    {
        cin>>xstart>>ystart>>xend>>yend>>xleft>>ytop>>xright>>ybottom;
        //cout<<max(xstart, xend)<<"  Hell"<<endl;
        bool flag=false;
        if(inside_the_rectangle(xstart, ystart, xend, yend, xleft, ytop, xright, ybottom)==true)
            flag=true;
        fuck++;
        Construct_General_Format(xstart, ystart, xend, yend, xleft, ytop, xright, ytop);
        if(Checking_Intersection(xstart, ystart, xend, yend, xleft, ytop, xright, ytop)==true)
            flag=true;
        fuck++;
        Construct_General_Format(xstart, ystart, xend, yend, xright, ytop, xright, ybottom);
        if(Checking_Intersection(xstart, ystart, xend, yend, xright, ytop, xright, ybottom)==true)
            flag=true;
        fuck++;
        Construct_General_Format(xstart, ystart, xend, yend,xright, ybottom, xleft, ybottom);
        if(Checking_Intersection(xstart, ystart, xend, yend,xright, ybottom, xleft, ybottom)==true)
            flag=true;
        fuck++;
        Construct_General_Format(xstart, ystart, xend, yend,xleft, ybottom, xleft, ytop);
        if(Checking_Intersection(xstart, ystart, xend, yend,xleft, ybottom, xleft, ytop)==true)
            flag=true;
        fuck++;
        if(flag==true)
            cout<<"T"<<endl;
        else cout<<"F"<<endl;
    }

    return 0;
}

