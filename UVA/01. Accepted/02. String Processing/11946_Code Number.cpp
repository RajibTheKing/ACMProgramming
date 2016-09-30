#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;

map<char, char> R;
char s[100];

int main()
{
    //freopen("test.txt", "r", stdin);
    R['0']='O'; R['1']='I'; R['2']='Z'; R['3']='E'; R['4']='A';
    R['5']='S'; R['6']='G'; R['7']='T'; R['8']='B'; R['9']='P';

    char c;
    int t, k;
    scanf("%d", &t);
    scanf("%c", &c);

    bool f=false;

    while(t--)
    {
        if(f)
            cout<<endl;

        //cout<<"for: "<<t<<endl;
        while(gets(s))
        {
            k=strlen(s);
            if(k==0) break;
            for(int i=0;i<k;i++)
            {
                c=s[i];
                if(c>='0'&&c<='9')
                    printf("%c", R[c]);
                else
                    printf("%c", c);
            }
            printf("\n");
        }
        f=true;
    }

    return 0;

}
