// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    
    int dp[1000005];
    dp[0] = A[0];
    
    for(int i=1; i<len; i++)
    {
        dp[i] = A[i] + dp[i-1];
        
        for(int dice = 2; dice<=6; dice++)
        {
            if(i-dice>=0)
            {
                dp[i] = max(dp[i], A[i] + dp[i-dice]);            
            }
        }
    }
    
    return dp[len-1];
}