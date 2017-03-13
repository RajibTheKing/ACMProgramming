#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>

#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    //freopen("/rajib/MyFiles/ProblemSolving/ACMProgramming/Codforces/CodeforcesRound375/input.txt", "r", stdin);

    int arr[3];
    while(cin>>arr[0]>>arr[1]>>arr[2])
    {

        sort(arr, arr+3);
        int ans = arr[2]-arr[1] + arr[1]-arr[0];

        cout<<ans<<endl;

    }

    return 0;

}
