
#include<bits/stdc++.h>
using namespace std;

int Compare(long long a, long long b, long long c, long long d)
{
    if (a==c && b==d) return 0;
    return (a*d > b*c)? 1: -1;
}

int main()
{
    int n, m;

    int left_n, left_m, right_m, right_n, now_n, now_m;

    while(cin>>n>>m)
    {
        if(n==1 && m==1) break;

        left_n = 0;
        left_m = 1;

        right_n = 1;
        right_m = 0;

        now_n = 1;
        now_m = 1;


        int temp = -1;

        while(true)
        {
            temp = Compare(now_n, now_m, n, m);
            if(temp == 0) break;


            if(temp == -1)
            {
                printf("R");
                left_n = now_n;
                left_m = now_m;

            }
            else
            {
                printf("L");
                right_n = now_n;
                right_m = now_m;
            }

            now_n = left_n+right_n;
            now_m = left_m+right_m;

            //printf("now_n, nowm = %d/%d, left_n/left_m = %d/%d , right_n/right_m = %d/%d\n", now_n, now_m, left_n, left_m, right_n, right_m);
            //getchar();
        }

        printf("\n");


    }
    return 0;
}

//Input
/*
5 7
878 323
1 1
*/
