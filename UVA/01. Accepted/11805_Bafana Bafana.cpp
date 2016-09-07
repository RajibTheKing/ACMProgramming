#include<iostream.h>
int main()
{
    int t, n[1005], k[1005], p[1005], ans[1005];
    int i, count, temp, j;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n[i]>>k[i]>>p[i];
    }
    for(i=0; i<t; i++)
    {
        temp=k[i];
        for(j=0; j<p[i]; j++)
        {
            temp++;
            if(temp>n[i])
                temp=1;
        }
        ans[i]=temp;
    }
    j=0;
    for(i=0; i<t; i++)
    {
        j++;

        printf("Case %d: %d\n", j, ans[i]);
    }




    return 0;
}
