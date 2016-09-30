#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;


class LittleElephantAndBallsAgain {
public:
    string SS;
    int dp[60][60];
    bool check(int i, int j)
    {
        if(i==j) return true;
        char c = SS[i];
        for(int p=i;p<=j;p++)
            if(SS[p]!=c) return false;
        return true;
    }
    int rec(int i, int j)
    {
        if(i>=SS.size()||j<0) return 0;
        if(i==j) return 0;
        if(check(i, j)) return 0;
        int &ret = dp[i][j];
        if(ret!=-1) return ret;
        ret = 9999;
        ret = min(ret, 1+rec(i+1, j));
        ret = min(ret, 1+rec(i, j-1));
        return ret;



    }
	int getNumber(string S)
	{
	    SS = S;
	    memset(dp, -1, sizeof(dp));
	    int ans = rec(0, S.size()-1);
	    return ans;



	}
};
