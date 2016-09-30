#include<iostream>
using namespace std;

int a, b, c, d, e, f;
long long F[1000000];

int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);

        F[0]=a;
        F[1]=b;
        F[2]=c;
        F[3]=d;
        F[4]=e;
        F[5]=f;
        for(int i=6;i<=n;i++)
            F[i]= (F[i-1]+F[i-2]+F[i-3]+F[i-4]+F[i-5]+F[i-6]) % 10000007;


        printf("Case %d: %lld\n", ++caseno, F[n] % 10000007);
    }
    return 0;
}
