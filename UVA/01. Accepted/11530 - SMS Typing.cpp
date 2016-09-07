#include<iostream.h>
#include<string.h>
char a[105];
main()
{
    int h[150];
    h[32]=1;
    h[97]=1;h[98]=2;h[99]=3;h[100]=1;h[101]=2;
    h[102]=3;h[103]=1;h[104]=2;h[105]=3;h[106]=1;
    h[107]=2;h[108]=3;h[109]=1;h[110]=2;h[111]=3;
    h[112]=1;h[113]=2;h[114]=3;h[115]=4;h[116]=1;
    h[117]=2;h[118]=3;h[119]=1;h[120]=2;h[121]=3;
    h[122]=4;
    int n, k, i, j, l, ans;
    gets(a);
    n=atoi(a);
    l=0;
    while(n)
    {
        ans=0;
        gets(a);
        k=strlen(a);
        for(i=0; i<k; i++)
        {
            j=a[i];
            ans=ans+h[j];
        }
        printf("Case #%d: %d\n",++l, ans);
        n--;
    }
}
