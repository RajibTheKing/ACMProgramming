#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>


using namespace std;

int findfact(int num)
{
    int i;
    int k=0;
    for(i=1;i<num;i++)
    {
        if(num%i==0)
            k++;

    }
    return k;
}




main()
{
    int n, m, t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int G = __gcd(n, m);
        //cout<<G<<endl;
        cout<<findfact(G)+1<<endl;

    }
}
