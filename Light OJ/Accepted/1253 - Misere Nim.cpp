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
    bool flag;
    int t,Stone, kase, N, NimHeap;
    scanf("%d", &t);
    for(kase=1;kase<=t;kase++)
    {
        scanf("%d", &N);

        NimHeap=0;
        flag=false;
        for(int i=0;i<N;i++)
        {
            scanf("%d", &Stone);
            NimHeap = NimHeap ^ Stone; //XOR Operation
            if(Stone>1) flag=true;
        }

        if(!flag)
        {
            if(NimHeap==0)  printf("Case %d: Alice\n", kase);
            else            printf("Case %d: Bob\n", kase);
        }
        else
        {
            if(NimHeap==0)  printf("Case %d: Bob\n", kase);
            else            printf("Case %d: Alice\n", kase);
        }
    }
    return 0;

}

