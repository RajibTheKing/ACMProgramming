#include<iostream.h>
int main()
{
    char a[1005];
    int n, m, i=0, j, temp;
    cin>>n;

    while(n)
    {
        scanf("%d ", &m);
        gets(a);
        temp=0;
        printf("%d ", ++i);
        for(j=0; j<strlen(a); j++, temp++)
        {
            if(temp==m-1)
                continue;
            printf("%c", a[j]);
        }

        cout<<endl;

        n--;
    }

    return 0;
}


