#include<iostream.h>
int main()
{
    int n, ans;
    int l, temp;
    int a[100];
    int i, j;
    cin>>n;
    while(n>0)
    {
        ans=0;
        cin>>l;
        for(i=0; i<l; i++)
            cin>>a[i];
        for(i=0; i<l; i++)
            for(j=i+1; j<l; j++)
                if(a[i]>a[j])
                    {
                        ans++;
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
        printf("Optimal train swapping takes %d swaps.\n", ans);
        n--;
    }
    return 0;
}
