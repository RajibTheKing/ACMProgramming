#include<iostream.h>
#include<stdio.h>
int main()
{
    while(1){
    int a[10000];
    int i, jn, mrr, n;
    cin>>n;
    if(n==0)
        goto end;
    for(i=0; i<n; i++)
        cin>>a[i];
    jn=0;
    mrr=0;
    for(i=0; i<n; i++)
    {
        if(a[i]==0)
            mrr++;
        else
            jn++;
    }
    printf("Mary won %d times and John won %d times\n", mrr, jn);
    }
end:
    return 0;
}
