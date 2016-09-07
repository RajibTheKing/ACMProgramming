#include<iostream.h>
#include<string.h>
int main()
{
    char a[15];
    int n, m, count,flag, q,cs=0;
    cin>>n;

    while(n--)
    {
        cin>>m;
        count=0;
        flag=0;


        while(m--)
        {

            scanf(" %s", a);
            q=strlen(a);
            if(a[0]=='s'&&a[1]=='h'&&a[2]=='e'&&a[3]=='e'&&a[4]=='p'&&q==5)
                flag=1;
            else
                flag=0;

            if(flag==1)
                count++;
            memset(a, 0, sizeof(a));
        }

        printf("Case %d: This list contains %d sheep.\n", ++cs, count);
        if(n>0)
            printf("\n");
    }
}
