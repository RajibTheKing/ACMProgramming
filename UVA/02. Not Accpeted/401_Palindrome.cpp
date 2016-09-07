#include<iostream.h>
#include<string.h>
char a[30];
main()
{
    char b, c;
    while(scanf("%s", a)==1)
    {
        int k, i, j, flag, p, mstring;
        k=strlen(a);

        for(i=0; i<k; i++)
        {
            if(a[i]=='A'||a[i]=='H'||a[i]=='I'||a[i]=='M'||a[i]=='O'||a[i]=='T')
                flag=1;
            else if(a[i]=='U'||a[i]=='V'||a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='1'||a[i]=='8'||a[i]=='0')
                flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            i=0; j=k-1; p=1;
            for(; ;)
            {
                if(a[i]!=a[j])
                {
                    p=0;
                    break;
                }
                i++;
                j--;
                if(i>j)
                    break;
            }
            if(p==1)
                printf("%s -- is a mirrored palindrome.\n", a);
            else
                printf("%s -- is not a palindrome.\n", a);


        }
        else
        {
            i=0; j=k-1; p=1;
            for(; ;)
            {
                if(a[i]!=a[j])
                {
                    p=0;
                    break;
                }
                i++;
                j--;
                if(i>j)
                    break;
            }
            if(p==1)
                printf("%s -- is a regular palindrome.\n", a);
            else
            {
                i=0; j=k-1; mstring=0;
                for(; ;)
                {
                    b=a[i]; c=a[j];
                    if(b=='3'&&c=='E') mstring=1;
                    else if(b=='E'&&c=='3') mstring=1;
                    else if(b=='H'&&c=='H') mstring=1;
                    else if(b=='I'&&c=='I') mstring=1;
                    else if(b=='J'&&c=='L') mstring=1;
                    else if(b=='L'&&c=='J') mstring=1;
                    else if(b=='M'&&c=='M') mstring=1;
                    else if(b=='O'&&c=='O') mstring=1;
                    else if(b=='S'&&c=='2') mstring=1;
                    else if(b=='T'&&c=='T') mstring=1;
                    else if(b=='U'&&c=='U') mstring=1;
                    else if(b=='V'&&c=='V') mstring=1;
                    else if(b=='W'&&c=='W') mstring=1;
                    else if(b=='X'&&c=='X') mstring=1;
                    else if(b=='Y'&&c=='Y') mstring=1;
                    else if(b=='Z'&&c=='5') mstring=1;
                    else if(b=='1'&&c=='1') mstring=1;
                    else if(b=='2'&&c=='S') mstring=1;
                    else if(b=='5'&&c=='Z') mstring=1;
                    else if(b=='8'&&c=='8') mstring=1;
                    else if(b=='A'&&c=='A') mstring=1;
                    else if(b=='0'&&c=='0') mstring=1;
                    else
                    {
                        mstring=0;
                        break;
                    }
                    i++;
                    j--; if(i>j)
                        break;
                }
                if(mstring==1)
                    printf("%s -- is a mirrored string.\n", a);
                else
                    printf("%s -- is not a palindrome.\n", a);

            }

        }
        memset(a, 0, 30*sizeof(char));

    }
}
