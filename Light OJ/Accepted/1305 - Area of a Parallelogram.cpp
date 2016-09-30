#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int main()
{
    double ax, ay, bx,by, cx, cy, dx , dy, p,q, h, ans, px, py, qx, qy;

    int t, kase=0, ans1, ans2, ans3;
    cin>>t;
    while(t--)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        p = (ax+cx)/2;
        q = (ay+cy)/2;

        dx = p*2 - bx;
        dy = q*2 - by;
        ans1 = int(dx);
        ans2 = int(dy);
        px = bx-ax;
        py = by-ay;

        qx = dx-ax;
        qy = dy-ay;

        ans = fabs(px*qy - py*qx);
        ans3=int(ans);

        printf("Case %d: %d %d %d\n", ++kase, ans1, ans2, ans3);
    }
    return 0;
}
