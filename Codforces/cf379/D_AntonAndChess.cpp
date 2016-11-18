#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
class Node
{
public:
    char name;
    LL posx, posy;
    LL mark;
    Node()
    {

    }

    Node(char c, LL x, LL y)
    {
        name = c;
        posx = x;
        posy = y;
        mark = 0;
    }
};

Node data[500005];
Node data1[500005]; //Straight
Node data2[500005]; //Cross

LL XX, YY;
bool isInline(LL x, LL y)
{
    if(x==XX) return true;
    if(y==YY) return true;
    if(abs(x-XX) == abs(y-YY)) return true;
    return false;
}

bool isBlocked(LL a, LL b, LL p, LL q)
{
    long long dist1 = (XX-a)*(XX-a) + (YY-b)*(YY-b);
    long long dist2 = (XX-p)*(XX-p) + (YY-q)*(YY-q);

    //cout<<"a,b,p,q = dist1,dist2: "<<a<<","<<b<<","<<p<<","<<q<<"-->"<<dist1<<","<<dist2<<endl;

    if(dist1>=dist2) return true;

    return false;
}

long long getDistance(LL a, LL b)
{
    long long dist = (XX-a)*(XX-a) + (YY-b)*(YY-b);
    return dist;
}
LL getPart(LL a, LL b)
{
    if(XX==a || b==YY)
    {
        if(a==XX && b>YY) return 0;
        else if(a==XX && b<YY) return 2;
        else if(a<XX && b==YY) return 1;
        else if(a>XX && b==YY) return 3;
    }
    else
    {
        if(a<XX && b>YY) return 0;
        else if(a<XX && b<YY) return 1;
        else if(a>XX && b<YY) return 2;
        else if(a>XX && b>YY) return 3;
    }
}

int main()
{
    LL n;
    LL x, y;
    char c;
    while(scanf("%I64d", &n)==1)
    {
        scanf("%I64d %I64d", &XX, &YY);
        LL indx = 0;
        for(LL i=0;i<n;i++)
        {
            scanf(" %c %I64d %I64d", &c, &x, &y);
            if(isInline(x,y))
            {
                data[indx++] = Node(c,x,y);
            }

        }

        Node closestRook[4];
        Node closestBishop[4];

        LL d1=0,d2=0;
        long long minRook[4], minBishop[4];

        for(LL i=0;i<4;i++)
        {
            minRook[i] =  4611686018427387904;
            minBishop[i] =  4611686018427387904;
            closestBishop[i].mark = -1;
            closestRook[i].mark = -1;
        }
        for(LL i=0;i<indx;i++)
        {
            c = data[i].name;
            x = data[i].posx;
            y = data[i].posy;
            if(x==XX || y==YY)
            {
                if(c=='B')
                {
                    long long dist = getDistance(x,y);
                    LL part = getPart(x,y);
                    if(minBishop[part]>dist)
                    {
                        minBishop[part] = dist;
                        closestBishop[part] = Node(c,x,y);
                    }
                }
                else
                {
                    data1[d1++] = Node(c,x,y);
                }
            }
            else
            {
                if(c=='R')
                {
                    long long dist = getDistance(x,y);
                    LL part = getPart(x,y);
                    if(minRook[part]>dist)
                    {
                        minRook[part] = dist;
                        closestRook[part] = Node(c,x,y);
                    }
                }
                else
                {
                    data2[d2++] = Node(c,x,y);
                }

            }
        }

        LL leftd1 = d1, leftd2 = d2;
        for(LL i=0;i<d1;i++)
        {
            //cout<<"D1: c,x,y = "<<c<<","<<x<<","<<y<<endl;
            c = data1[i].name;
            x = data1[i].posx;
            y = data1[i].posy;

            LL part = getPart(x,y);
            if(closestBishop[part].mark==-1) continue;

            if(isBlocked(x,y,closestBishop[part].posx, closestBishop[part].posy))
            {
                leftd1--;
            }

        }

        for(LL i=0;i<d2;i++)
        {
            c = data2[i].name;
            x = data2[i].posx;
            y = data2[i].posy;

            LL part = getPart(x,y);

            if(closestRook[part].mark==-1) continue;

            if(isBlocked(x,y,closestRook[part].posx, closestRook[part].posy))
            {
                leftd2--;
            }

        }

        if(leftd1|leftd2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
}


