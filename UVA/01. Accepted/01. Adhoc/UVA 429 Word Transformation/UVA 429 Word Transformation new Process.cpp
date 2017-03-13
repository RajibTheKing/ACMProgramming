#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

using namespace std;


int totalWord;
int color [200 + 10];
string Words[200 + 10];

struct Node
{
    string str;
    int cost;

    Node (string a, int c)
    {
        str = a;
        cost = c;
    }


};

bool isOneCharDiff (string a, string b)
{
    if ( a.length() != b.length() ) return false;

    int cnt = 0;

    for ( int i = 0; i < a.length(); i++ )
    {
        if ( a [i] != b [i] ) cnt++;
    }

    if(cnt==1) return true;
    return false;

}



int doBFS (string st, string ed)
{
    Node temp("hello", 0);
    queue <Node> Q;
    while ( !Q.empty() ) Q.pop();

    Q.push(Node (st, 0));
    memset(color, 0, sizeof(color));

    while (!Q.empty())
    {
        temp = Q.front(); Q.pop();
        if (temp.str == ed ) return temp.cost;

        for ( int i = 0; i < totalWord; i++ )
        {
            if (color[i]==0)
            {
                if ( isOneCharDiff (temp.str, Words[i]))
                {
                    Q.push(Node (Words[i], temp.cost + 1));
                    color[i]=1;
                }
            }
        }
    }

    return 0;

}

int main()
{
    //freopen("input.txt","r", stdin);
    int testCase;
    scanf ("%d", &testCase);
    getchar ();
    getchar ();

    for(int cs=0; cs<testCase;cs++)
    {
        char input [100];
        totalWord = 0;

        while (gets (input) && strcmp (input, "*"))
        {
            Words [totalWord] = input;
            totalWord++;
        }

        if (cs) printf ("\n");

        while ( gets (input) && strlen (input) )
        {
            char *pch;
            string a, b;
            pch = strtok(input, " ");
            a = pch;
            pch = strtok (NULL, " ");
            b = pch;
            cout << a << " " << b;
            printf (" %d\n", doBFS(a, b));
        }
    }

    return 0;
}
