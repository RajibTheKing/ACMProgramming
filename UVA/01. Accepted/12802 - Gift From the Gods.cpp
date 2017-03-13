#include<bits/stdc++.h>
using namespace std;
#define SZ 1000010
int primes[100000];
bool flag[SZ];


void Sieve()
{

    memset(flag, 0, sizeof(flag));
    flag[0] = true;
    flag[1] = true;
    int indx=0;
    for(int i=2;i<SZ;i++)
    {
        if(flag[i]==false)
        {
            primes[indx++] = i;
            for(int j=i+i;j<SZ;j+=i)
            {
                flag[j]=true;
            }
        }
    }
}

int update(int nowans, int p)
{
    if(p==1) return nowans;

    if(p%2==0)
        nowans*=1;
    else
    {
        int t = p+1;
        if(t%4==0)
        {
            nowans*=1;
        }
        else
        {
            nowans*=(-1);
        }
    }

    return nowans;
}

bool rec(int i, int j, string s)
{
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    return rec(i+1, j-1, s);
}
bool isPalindrome(int n)
{
    stringstream ss;
    ss.clear();
    ss<<n;
    string s1, s2;
    ss>>s1;
    return rec(0, s1.size()-1, s1);
}
int main()
{
    Sieve();
    int n;
    while(cin>>n)
    {
        cout<<n*2<<endl;
        if(flag[n]==false)
        {
            if(isPalindrome(n))
                break;
        }
    }
    return 0;
}
