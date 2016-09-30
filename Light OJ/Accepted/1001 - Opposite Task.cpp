#include<iostream>
using namespace std;

typedef struct node
{
    int a;
    int b;

};

node ans[30];
void initialize()
{
    for(int i=0;i<30;i++)
    {
        ans[i].a=-1;
        ans[i].b=-1;
    }
}
main()
{
   initialize();
   int T, n;
   cin>>T;
   while(T--)
   {
       cin>>n;
       if(ans[n].a==-1)
       {
           if(n>10)
           {
               ans[n].a=n-10;
               ans[n].b=10;
           }
           else
           {
               ans[n].a=0; ans[n].b=n;
           }

           cout<<ans[n].a<<" "<<ans[n].b<<endl;
       }
       else
       {
           if(ans[n].a!=10 && ans[n].b!=0)
            {
                ans[n].a++;
                ans[n].b--;
            }

            cout<<ans[n].a<<" "<<ans[n].b<<endl;
       }

   }
}
