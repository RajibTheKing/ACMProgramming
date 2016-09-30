#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;
int a[110][110],c,m,n;
bool flag[110][110];
int func1(int i,int j)
{
    if(i==m-1&&j==n-1)
        return c;
    if(a[i+1][j]>=a[i][j+1])
    {
        flag[i+1][j]=1;
        c+=a[i+1][j];
        return func1(i+1,j);
    }
    else
    {
        flag[i][j+1]=1;
        c+=a[i][j+1];
        return func1(i,j+1);
    }
}
int func2(int i,int j)
{
    cout<<c<<endl;

    if(i==0&&j==0)
    {
        return c;
    }

    if(i-1>=0&&j-1>=0&&flag[i-1][j]==0&&flag[i][j-1]==0)
    {
        if(a[i-1][j]>=a[i][j-1])
        {
            flag[i-1][j]=1;
            c+=a[i-1][j];
            func2(i-1,j);
        }
        else
        {
            flag[i][j-1]=1;
            c+=a[i][j-1];
            func2(i,j-1);
        }
    }
    else if(i-1>=0&&flag[i-1][j]==0&&flag[i][j-1])
    {
        flag[i-1][j]=1;
        c+=a[i-1][j];
        func2(i-1,j);
    }
    else if(j-1>=0&&flag[i][j-1]==0&&flag[i][j-1])
    {
        flag[i][j-1]=1;
        c+=a[i][j-1];
        func2(i,j-1);
    }

}

main()
{
    int i,j,test, p1, p2;
    scanf("%d", &test);
    while(test--)
    {

        cin>>m>>n;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j];
        int ans=func1(0,0);
        cout<<ans<<endl;
        c=0;
        int ans1=func2(m-1,n-1);
        cout<<"fff"<<endl;
        cout<<ans1<<endl;
    }


}

