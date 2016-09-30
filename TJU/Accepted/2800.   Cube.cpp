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
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("%d %d\n", n*n-n+1, n*n+n-1);
    }
    return 0;

}


