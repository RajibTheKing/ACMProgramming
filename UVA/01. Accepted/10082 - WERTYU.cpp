#include<iostream.h>
main()
{
    char p[14]={"`1234567890-="};
    char q[13]={"QWERTYUIOP[]"};
    char r[12]={"ASDFGHJKL;'"};
    char s[11]={"ZXCVBNM,./"};
    char a;
    int i, j, k, flag=0;
    while(scanf("%c", &a)==1)
    {
        for(i=0; i<14; i++)
        {
            if(p[i]==a)
            {
                cout<<p[i-1];
                flag=1;
                break;
            }
            if(q[i]==a)
            {
                cout<<q[i-1];
                flag=1;
                break;
            }
            if(r[i]==a)
            {
                cout<<r[i-1];
                flag=1;
                break;
            }
            if(s[i]==a)
            {
                cout<<s[i-1];
                flag=1;
                break;
            }


        }
        if(flag==0)
        {
            cout<<a;
            flag=0;
        }
        flag=0;
    }

}
