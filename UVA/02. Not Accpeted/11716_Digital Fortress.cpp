#include<iostream.h>
#include<string.h>
#include<math.h>
char a[1000], c[100][100];
int main()
{
    int square, i, j, k, n, r;
    cin>>n;
    while(scanf("%s", a)==1)
    {
        k=strlen(a);
        n=sqrt(k);
        r=-1;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                c[i][j]=a[++r];
        for(j=0; j<n; j++)
            for(i=0; i<n; i++)
                cout<<c[i][j];
        cout<<endl;

    }
    return 0;
}
