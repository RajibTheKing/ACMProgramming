#include<bits/stdc++.h>
using namespace std;

char vowels[] = {'A','E','I','O','U','Y'};
bool isVowel(char c)
{
    for(int i=0;i<6;i++)
    {
        if(c==vowels[i]) return true;
    }

    return false;
}
int main()
{
    string str;
    while(cin>>str)
    {
        int indx = 0;
        int mx = 0;
        str = "A"  +  str;
        str = str + "A";
        for(int i=0;i<str.size();i++)
        {
            if(isVowel(str[i]))
            {
                mx = max(mx, i-indx);
                indx = i;
            }
        }
        cout<<mx<<endl;
    }

    return 0;
}
