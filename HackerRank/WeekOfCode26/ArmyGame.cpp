#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    int n;
    int m;
    while(cin >> n >> m)
    {


        int r = n/2;
        int c = m/2;
        if(n%2==1)
            r++;
        if(m%2==1)
            c++;
        int ans = r*c;
        cout<<ans<<endl;
    }

    return 0;
}
