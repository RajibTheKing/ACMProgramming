#include<iostream.h>
#include<string.h>
char a[1000];
char b[1000];
char z[1000];
long add(char x[], char y[])
{

    int i, limit;
    int k, l, m;
    int ad, h=0;
    k=strlen(x);
    l=strlen(y);
    if(k>l) limit = k; else limit = l;
    m=limit+1;

   for(i=0; i<=limit; i++ )
    {
        ad=(x[--k]+y[--l])-48+h;
        if(k==0) {k=1; x[0]='0';}
        if(l==0) {l=1; y[0]='0';}
        if(ad>57)
        {
            ad=ad-58;
            z[--m]=ad+48;
            h=1;
        }
        else
        {
            z[--m]=ad;
            h=0;
        }
    }
    printf("Sum: ");
    if(z[0]!='0')
        cout<<z[0];
    for(i=1; i<=limit; i++)
        cout<<z[i];
    return 0;

}
int main()
{
    while(1){
    gets(a);
    gets(b);
    add(a, b);
    cout<<"\n";
    }
}
