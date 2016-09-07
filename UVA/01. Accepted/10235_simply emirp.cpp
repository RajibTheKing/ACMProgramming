#include<iostream.h>
#include<string.h>
#include<math.h>
int prime[79000], flag[1000001], n, a[7];
int search(int a)
{
    int f, i, j, mid;
    f=0; i=0; j=79000;
    while(i<j)
    {
        mid=floor((i+j)/2);

        if(a>prime[mid])
            i=mid+1;
        else
            j=mid;

        if(prime[mid]==a)
        {
            f=1; break;
        }
    }

    return f;
}
int reverse(void)
{
    int t, i, j;
    t=n;
    if(t<10)
        return t;
    for(i=0; ; i++)
    {
      a[i]=t%10; t=t/10;
      if(t==0)
            break;
    }
    t=0;
    for(j=0; j<=i; j++)
        t=t*10+a[j];

    return t;
}
int main()
{
    int i, j,k=0;
    for(i=2; i<=1000000; i++)
        if(flag[i]==0)
        {
            prime[k++]=i;
            for(j=i+i; j<=1000000; j=j+i)
            {
                flag[j]=1;
            }
        }

   while(scanf("%d", &n)==1)
    {
        int f1=0, f2=0, temp;
        f1 = search(n);
        temp=reverse();
        f2=search(temp);
        if(temp==n)
            f2=0;

        if(f1==1&&f2==0)
            printf("%d is prime.\n", n);
        else if(f1==1&&f2==1)
            printf("%d is emirp.\n", n);
        else
            printf("%d is not prime.\n", n);
    }
    return 0;
}

