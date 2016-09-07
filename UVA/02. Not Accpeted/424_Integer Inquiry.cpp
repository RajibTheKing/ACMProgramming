#include<iostream.h>
#include<string.h>
char a[110], b[110], result[110];

main()
{
    int i, j, k, h, temp;
    memset(a, 0, 110*sizeof(char));
    //cout<<a[0];
    while(1)
    {
        gets(b);
        if(a[0]=='0')
            break;
        k=strlen(b);
        j=106;
        h=0;
        for(i=k-1; i>=0; i--)
        {
            temp=a[i]+b[i]+h-48;
            if(temp>10)
            {
                h=1;
                temp=temp%10;
            }

        }



    }


}
