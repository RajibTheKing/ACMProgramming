#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct Point
{
    long long x, y;
    long long f;
};



long long dis(Point p1, Point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

bool isParallel(Point A, Point B, Point C, Point D)
{
    //Here is AB parallel to CD
    long long p, q, r, s;

    p = (A.y-B.y)*(C.x-D.x);
    q = (C.y-D.y)*(A.x-B.x);
    if(p==q) return true;

    return false;
}

bool isSquare(Point A, Point B, Point C, Point D)
{
    if(dis(A,B)==dis(C,D) && dis(A,D)==dis(B,C) && dis(A,B)==dis(B,C))
    {
        long long p, q, r;
        r = dis(A,C);
        p = dis(A,B);
        q = dis(A,D);

        if(r==(p+q)) return true;
    }
    return false;
}

bool isRhombus(Point A, Point B, Point C, Point D)
{
    if(dis(A,B)==dis(C,D) && dis(A,D)==dis(B,C) && dis(A,B)==dis(B,C))
    {
        //if( check(slop(A,B),slop(C,D)) && check(slop(A,D),slop(B,C)) )
        if(isParallel(A,B, C,D)&&isParallel(A,D, B,C))
            return true;
    }
    return false;
}

bool isRectangle(Point A, Point B, Point C, Point D)
{
    if(dis(A,B)==dis(C,D) && dis(A,D)==dis(B,C))
    {
        long long p, q, r;
        r = dis(A,C);
        p = dis(A,B);
        q = dis(A,D);

        if(r==(p+q)) return true;
    }
    return false;
}



bool isParallelogram(Point A, Point B, Point C, Point D)
{
    if(dis(A,B)==dis(C,D) && dis(A,D)==dis(B,C))
    {
        //if( check(slop(A,B),slop(C,D)) && check(slop(A,D),slop(B, C)) )
        if(isParallel(A,B, C,D)&&isParallel(A,D, B,C))
            return true;
    }

    return false;
}


bool isTrapezium(Point A, Point B, Point C, Point D)
{
    if(isParallel(A,B, C,D)) return true;
    if(isParallel(A,D, B,C)) return true;
    return false;

}



bool cmp(Point A, Point B)
{
    return A.f<B.f;
}

int main()
{
    freopen("input.txt", "r", stdin);
    Point p[4];

    long long T, kase=0;
    scanf("%lld", &T);
    while(T--)
    {
        for(int i=0;i<4;i++)
        {
            scanf("%lld %lld", &p[i].x, &p[i].y);
            p[i].f=i;
        }

        printf("Case %lld: ", ++kase);
        int flag;
        flag=6;
        do{
            //cout<<"Here"<<endl;
            //for(int i=0;i<4;i++) cout<<"   "<<p[i].x<<", "<<p[i].y;
            //cout<<endl;
            if(isSquare(p[0], p[1], p[2], p[3])) flag=min(flag,1);
            if(isRectangle(p[0], p[1], p[2], p[3])) flag=min(flag,2);
            if(isRhombus(p[0], p[1], p[2], p[3])) flag=min(flag,3);
            if(isParallelogram(p[0], p[1], p[2], p[3])) flag=min(flag,4);
            if(isTrapezium(p[0], p[1], p[2], p[3])) flag=min(flag,5);

        }while(std::next_permutation(p,p+4, cmp) );

        if(flag==1) printf("Square\n");
        if(flag==2) printf("Rectangle\n");
        if(flag==3) printf("Rhombus\n");
        if(flag==4) printf("Parallelogram\n");
        if(flag==5) printf("Trapezium\n");
        if(flag==6) printf("Ordinary Quadrilateral\n");
    }

    return 0;

}
