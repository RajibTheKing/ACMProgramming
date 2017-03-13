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
    int n, t1, t2, temp, kount;

    while(scanf("%d", &n)==1)
    {
        kount=0;
        if(n==0) break;
        printf ("Original number was %d\n", n);
        char n1[100], n2[100];

        sprintf (n1, "%d", n);
        sort(n1, n1+strlen(n1));
        strcpy(n2, n1);
        reverse(n2, n2+strlen(n2));

        map<int, bool> R;
        t1 = atoi(n1);
        t2 = atoi(n2);
        temp = t2-t1;
        printf ("%d - %d = %d\n", t2, t1, temp);
        while(R[temp]==false)
        {

            R[temp]=true;
            n=temp;
            sprintf (n1, "%d", n);
            sort(n1, n1+strlen(n1));
            strcpy(n2, n1);
            reverse(n2, n2+strlen(n2));
            t1 = atoi(n1);
            t2 = atoi(n2);
            temp = t2-t1;
            kount++;
            printf ("%d - %d = %d\n", t2, t1, temp);
        }

        printf("Chain length %d\n\n", kount+1);


    }


    return 0;
}

