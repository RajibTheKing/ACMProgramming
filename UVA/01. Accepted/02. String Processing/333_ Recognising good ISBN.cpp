#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;
char a[1000];

void trim(char *str)
{
	long i ,j ,len , k , l;

	for(i = 0;str[i] == ' ';i++);
	len = strlen(str);

	for(j = len - 1;str[j] == ' ';j--);
	k = 0;
	for(l = i;l<=j;l++)
		str[k++] = str[l];
	str[k] = NULL;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int len, temp, s1, s2, digit;
    bool flag;
    string s;
    while(gets(a))
    {
        trim(a);
        flag=true;
        len=strlen(a);
        s1=0;
        s2=0;
        digit=0;
        for(int i=0;i<len;i++)
        {
            if(a[i]>='0'&&a[i]<='9')
            {
                digit++;
                s1+=a[i]-'0';
                s2+=s1;
            }
            else if(a[i]=='X'&&digit==9)
            {
                digit++;
                s1+=10;
                s2+=s1;
            }
            else if(a[i]!='-')
            {
                flag=false;
                break;
            }

        }

        if(s2%11==0&&digit==10&&flag==true)
            printf("%s is correct.\n", a);
        else
            printf("%s is incorrect.\n", a);
        memset(a, 0, sizeof(a));
    }

    return 0;
}
