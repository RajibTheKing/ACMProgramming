#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    int temp;

    while(cin>>N>>M)
    {
        int ans=0;
        for(int i=0;i<N;i++)
        {
            bool flag = true;
            for(int j=0;j<M;j++)
            {
                cin>>temp;
                if(temp==0)
                {
                    flag=false;
                }
            }
            if(flag) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

