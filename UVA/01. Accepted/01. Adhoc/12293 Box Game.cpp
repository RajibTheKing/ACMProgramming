#include <stdio.h>
#define LL long long

int main ()
{
    LL n;

    while ( scanf ("%lld", &n) && n ) {
        LL num = 1;
        while ( num < n ) {
            num *= 2;
            num++;
        }

        if ( num == n ) printf ("Bob\n");
        else printf ("Alice\n");
    }

    return 0;
}
