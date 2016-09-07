#include<iostream.h>
#include<string.h>
int main()
{
    int k, i, flag=0, f=0;
    char a;
    char p[13]="qwertyuiop[]";
    char q[12]="asdfghjkl;'";
    char r[11]="zxcvbnm,./";
    while(scanf("%c", &a)==1)
    {
        for(i=0; i<13; i++)
        {
            if(a==' ')
            {
                f=1;
                flag=1;
                break;
            }
            if(p[i]==a)
            {
                f=1;
                cout<<p[i-2];
                break;
            }
            if(q[i]==a)
            {
                f=1;
                cout<<q[i-2];
                break;
            }
            if(r[i]==a)
            {
                f=1;
                cout<<r[i-2];
                break;
            }
        }
        if(flag==1)
        {
            flag=0;
            printf("%c", a);
        }
        if(f==0)
            cout<<a;
        f=0;

    }
    return 0;
}
