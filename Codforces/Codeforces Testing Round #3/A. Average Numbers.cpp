#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define sz 200010
bool flag[sz];
typedef struct node
{
    int x;
    int h;
    int a[200000];
};

node b[1010];

int a[sz],  c[sz];

main()
{


    int n, l;
    double sum=0, temp;
    memset(flag, 0, sizeof(flag));
    for(int i=0;i<sz;i++)
    {
        b[i].x=0;
        b[i].h=-1;
    }

    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
        b[a[i]].x++;
        b[a[i]].a[++b[a[i]].h]=i;
    }



    int p=-1;
    int kount = 0;
    for(int i=0;i<n;i++)
    {
        temp=sum-a[i];
        temp=temp/(n-1);
        //cout<<"temp: "<<temp<<endl;
        if(floor(temp)==temp)
        {
            l = int(temp);
            if(flag[l]==1)
                continue;
            flag[l]=1;

            if(b[l].x!=0)
            {
                kount+=b[l].x;
                for(int t=0;t<=b[l].h;t++)
                    c[++p]=b[l].a[t];

            }
        }

    }

    cout<<kount<<endl;
    if(kount)
    {
        std::sort(c, c+p+1);
        for(int i=0;i<=p;i++)
            cout<<c[i]+1<<" ";
        cout<<endl;
    }




}
