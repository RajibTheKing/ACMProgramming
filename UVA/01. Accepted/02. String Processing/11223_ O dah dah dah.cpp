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



map<string, string> Set;

void generalize(void);
int main()
{
    char s[2005];
    string a;
    generalize();
    int Test, kase=0;
    scanf("%d", &Test);
    getchar();
    bool f=false;
    while(Test--)
    {
        if(f) cout<<endl;
        f=true;
        gets(s);
        a="";
        bool flag=false;
        printf("Message #%d\n", ++kase);
        for(int i=0;i<strlen(s);i++)
        {
            if(flag==false&&s[i]!=' ')
            {
                a+=s[i];


            }
            else if(flag==false&&s[i]==' ')
            {
                cout<<Set[a];
                a="";
                flag=true;
            }
            else if(flag==true&&s[i]==' ')
            {
                cout<<" ";
            }
            else
            {
                a+=s[i];
                flag=false;
            }
        }
        cout<<Set[a]<<endl;


    }

    return 0;
}
void generalize(void)
{
    Set[".-"] = "A";
    Set[".---"] = "J";
    Set["..."] = "S";
    Set[".----"] = "1";
    Set[".-.-.-"] = ".";
    Set["---..."] = ":";
    Set["-..."] = "B";
    Set["-.-"] = "K";
    Set["-"] = "T";
    Set["..---"] = "2";
    Set["--..--"] = ",";
    Set["-.-.-."] = ";";
    Set["-.-."] = "C";
    Set[".-.."] = "L";
    Set["..-"] = "U";
    Set["...--"] = "3";
    Set["..--.."] = "?";
    Set["-...-"] = "=";
    Set["-.."] = "D";
    Set["--"] = "M";
    Set["...-"] = "V";
    Set["....-"] = "4";
    Set[".----."] = "'";
    Set[".-.-."] = "+";
    Set["."] = "E";
    Set["-."] = "N";
    Set[".--"] = "W";
    Set["....."] = "5";
    Set["-.-.--"] = "!";
    Set["-....-"] = "-";
    Set["..-."] = "F";
    Set["---"] = "O";
    Set["-..-"] = "X";
    Set["-...."] = "6";
    Set["-..-."] = "/";
    Set["..--.-"] = "_";
    Set["--."] = "G";
    Set[".--."] = "P";
    Set["-.--"] = "Y";
    Set["--..."] = "7";
    Set["-.--."] = "(";
    char c='"';
    Set[".-..-."] = c;
    Set["...."] = "H";
    Set["--.-"] = "Q";
    Set["--.."] = "Z";
    Set["---.."] = "8";
    Set["-.--.-"] = ")";
    Set[".--.-."] = "@";
    Set[".."] = "I";
    Set[".-."] = "R";
    Set["-----"] = "0";
    Set["----."] = "9";
    Set[".-..."] = "&";

}

