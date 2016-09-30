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

int a[500];
int num[500];
int n, t;
bool flag;
map<string, bool> R;

void subset(int ind, int pre)
{
    int i;
    int sum=0;
    string s="";
    stringstream ss;
    for(i=0;i<=ind-1;i++)
    {
        string q="";
        ss.clear();
        ss<<num[a[i]];
        ss>>q;
        //cout<<num[a[i]]<<" ";
        sum+=num[a[i]];
        s+=q;

    }
    if(sum==t&&R[s]==false)
    {
        flag=true;
        for(i=0;i<ind;i++)
        {
            if(i==0)
                printf("%d", num[a[i]]);
            else
                printf("+%d", num[a[i]]);
        }
        cout<<endl;
        R[s]=true;

    }



    for(i=pre+1;i<=n;i++)
    {
        a[ind]=i;
        subset(ind+1, i);
    }
}
int main()
{
    //freopen("data.txt", "w", stdout);
    while(cin>>t>>n)
    {
        flag=false;
        if(t==0&&n==0) break;


        for(int i=1;i<=n;i++)
            cin>>num[i];

        printf("Sums of %d:\n", t);

        subset(0,0);
        if(flag==false)
            cout<<"NONE"<<endl;

        R.clear();

    }


    return 0;
}


