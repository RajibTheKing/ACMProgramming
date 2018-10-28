// you can use includes, for example:
 #include <algorithm>
 #include <string.h>
 

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int dp[20005][1005];
int getAbs(int a)
{
    if(a<0) return a*(-1);
    return a;
}
int rec(int cur, int sum, vector<int> &A)
{
    if(cur == A.size() - 1)
    {
        //cout<<"Here: "<<sum<<endl;
        return sum;
    }
    
    int &ret = dp[cur][sum + 500];
    if(ret!=-1) return ret;
    
    ret = 200;
    if(sum + A[cur+1] <= 500)
    {
        ret = min(ret, getAbs(rec(cur+1, sum+A[cur+1], A)));
    }
    
    if(sum - A[cur+1] >= -500)
    {
        ret = min(ret, getAbs(rec(cur+1, sum-A[cur+1], A)));
    }
    
    return ret;
    
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() == 0)
    {
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    return getAbs(min(rec(0, A[0], A), rec(0, -A[0], A)));   
}