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
typedef long long LL;
#define sz 10000
int num[1000000];
bool flag[sz+100];

void Compute(void)
{
    int k=-1;
    for(int i=1;i<=sz;i++)
    {
        if(flag[i]==0)
        {
            num[++k]=i;
            for(int j=i;j<=sz;)
            {
                char c[50];

                sprintf(c, "%d", j);
                int temp=0;
                for(int q=0;q<strlen(c);q++)
                    temp+=c[q]-'0';
                temp+=j;
                flag[temp]=true;
                //cout<<temp<<endl;
                j=temp;
            }
        }
    }


}

int main()
{

    Compute();

    for(int i=0;i<=982; i++)
        cout<<num[i]<<endl;

    return 0;
}


