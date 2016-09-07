#include<iostream.h>
int main()
{
    int e[16], f[16], c[16], n, temp, total[16], k, p;
    int i;
    cin>>n;
    for(i=0;i<n ; i++)
    {
        cin>>e[i]>>f[i]>>c[i];
    }

    for(i=0; i<n;i++)
    {
        temp=0;
        k=e[i]+f[i];
        total[i]=0;
        for(; ;)
        {
            p=k/c[i];
            if(p==0)
                break;
            total[i]=total[i]+p;

            temp=k%c[i];
            k=p+temp;
        }

    }
    for(i=0; i<n; i++)
    {
        cout<<total[i]<<"\n";
    }
    return 0;
}
