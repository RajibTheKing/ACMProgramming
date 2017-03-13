#include<iostream>
#include<string.h>
using namespace std;

typedef struct node
{
    int f;
    string str;
};

node tt[100000];

int main()
{
    string ss[1005], name, temp;
    int ssi[1005];
    bool flag, ff[1005];
    int n, i, j, k, min, point;


    while(cin>>n)
    {
        for(int u=0;u<100000;u++)
            tt[u].f=1;
        memset(ff, true, sizeof(ff));
        k=0;
        for(i=1;i<=n;i++)
        {
            cin>>temp;
            cin>>point;
            flag=false;

            for(j=1;j<=k;j++)
                if(temp==ss[j])
                {
                    flag=true;
                    break;
                }

            if(flag==false)
            {
                ss[++k]=temp;
                ssi[k]=point;
                if(point<0)
                    ff[k]=false;
                else
                {
                    if(tt[point].f==1)
                    {
                        tt[point].str=temp;
                        tt[point].f=2;

                    }
                }

            }
            else
            {
                ssi[j]+=point;
                if(point<0)
                    ff[j]=false;
                else
                {
                    point=ssi[j];

                    if(tt[point].f==1 && ff[j]==true)
                    {
                        tt[point].str=ss[j];
                        tt[point].f=2;

                    }
                }
            }

        }



        for(i=99999;i>=0;i--)
            if(tt[i].f==2)
            {
                name=tt[i].str;
                break;
            }


        cout<<name<<endl;
    }

    return 0;
}
