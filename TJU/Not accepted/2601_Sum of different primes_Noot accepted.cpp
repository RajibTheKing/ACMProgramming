#include<iostream.h>
#include<math.h>
int prime[1001];
int main()
{
    int i, j, flag, c=0;
    for(i=2; ; i++)
    {
        flag=1;
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            c++;
            prime[c]=i;
        }
        if(c==999)
            break;
    }


    while(1)
    {
        long long  count=0;
        int n, k, dd;
        int a, b, c, d, e, f, g, h, i, j, l, m, o, p;
        cin>>n>>k;
        if(n==0&&k==0)
            goto end;
        dd=n/2+1;
        if(k==1)
            for(a=1; a<=dd; a++)
                if(prime[a]==n)
                    {
                        count++;
                        break;
                    }
        if(k==2)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    if(prime[a]+prime[b]==n)
                        count++;

        if(k==3)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    for(c=b+1; prime[c]<n; c++)
                        if(prime[a]+prime[b]+prime[c]==n)
                            count++;

        if(k==4)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    for(c=b+1; prime[c]<n; c++)
                        for(d=c+1; prime[d]<n; d++)
                            if(prime[a]+prime[b]+prime[c]+prime[d]==n)
                                count++;
        if(k==5)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    for(c=b+1; prime[c]<n; c++)
                        for(d=c+1; prime[d]<n; d++)
                            for(e=d+1; prime[e]<n; e++)
                                if(prime[a]+prime[b]+prime[c]+prime[d]+prime[e]==n)
                                    count++;
        if(k==6)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    for(c=b+1; prime[c]<n; c++)
                        for(d=c+1; prime[d]<n; d++)
                            for(e=d+1; prime[e]<n; e++)
                                for(f=e+1; prime[f]<n; f++)
                                    if(prime[a]+prime[b]+prime[c]+prime[d]+prime[e]+prime[f]==n)
                                        count++;

        if(k==7)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    for(c=b+1; prime[c]<n; c++)
                        for(d=c+1; prime[d]<n; d++)
                            for(e=d+1; prime[e]<n; e++)
                                for(f=e+1; prime[f]<n; f++)
                                    for(g=f+1; prime[g]<n; g++)
                                        if(prime[a]+prime[b]+prime[c]+prime[d]+prime[e]+prime[f]+prime[g]==n)
                                            count++;

        if(k==8)
            for(a=1;a<dd; a++)
                for(b=a+1; prime[b]<n; b++)
                    for(c=b+1; prime[c]<n; c++)
                        for(d=c+1; prime[d]<n; d++)
                            for(e=d+1; prime[e]<n; e++)
                                for(f=e+1; prime[f]<n; f++)
                                    for(g=f+1; prime[g]<n; g++)
                                        for(h=g+1; prime[h]<n; h++)
                                            if(prime[a]+prime[b]+prime[c]+prime[d]+prime[e]+prime[f]+prime[g]+prime[h]==n)
                                                count++;



        cout<<count<<"\n";

    }
end:
return 0;

}
