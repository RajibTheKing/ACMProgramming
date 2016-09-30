#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x;
    int test;
    cin>>test;
    int kase = 0;
    while(test--)
    {
        cin>>n>>k>>x;
        int total = (n*(n+1))/2;

        int n1 = x-1;
        int n2 = x+k-1;

        int t1 = (n1*(n1+1))/2;
        int t2 = (n2*(n2+1))/2;
        printf("Case %d: ", ++kase);
        cout<<total-(t2-t1)<<endl;
    }
    return 0;
}
/*12345
2 2
123456
3 1
1+3
*/
