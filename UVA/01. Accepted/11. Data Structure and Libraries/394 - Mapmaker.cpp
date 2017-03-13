#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;

typedef struct Pair
{
    int L;
    int U;
};

typedef struct node
{
    int B;
    int C_D;
    int D;
    Pair p[100];
};


int main()
{
    //freopen("input.txt", "r", stdin);
    int N, R, address;
    int I[100];
    int C[100];
    map<string, node> M;
    string name;
    node temp;
    while(cin>>N>>R)
    {
        getchar();
        M.clear();
        for(int i=0;i<N;i++)
        {
            cin>>name;
            cin>>temp.B;
            cin>>temp.C_D;
            cin>>temp.D;
            for(int j=1;j<=temp.D;j++)
            {
                cin>>temp.p[j].L;
                cin>>temp.p[j].U;
            }
            M[name]=temp;
        }
        for(int i=0;i<R;i++)
        {
            memset(I, 0, sizeof(I));
            memset(C, 0, sizeof(C));
            cin>>name;
            temp=M[name];
            for(int j=1;j<=temp.D;j++)
                cin>>I[j];
            C[temp.D]=temp.C_D;
            for(int k=temp.D-1;k>=1;k--)
            {
                C[k]=C[k+1]*(temp.p[k+1].U - temp.p[k+1].L+1);
                //cout<<C[k]<<endl;
            }
            C[0]=temp.B;
            for(int k=1;k<=temp.D;k++)
                C[0]-=C[k]*temp.p[k].L;
            address=C[0];
            for(int k=1;k<=temp.D;k++)
                address+=C[k]*I[k];
            cout<<name<<"[";
            for(int k=1;k<=temp.D;k++)
            {
                if(k==1)
                    cout<<I[k];
                else
                    cout<<", "<<I[k];
            }
            cout<<"] = "<<address<<endl;

        }
    }

    return 0;
}
