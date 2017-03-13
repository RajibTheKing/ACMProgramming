#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    map<string, string> M;
    M.clear();
    string s, x="";
    while(getline(cin, s))
    {
        if(s.size()==0) break;
        //cout<<s<<endl;
        string t="";
        int i;
        for(i=0;i<s.size();i++)
        {
            if(s[i]==' ') break;
            t+=s[i];
        }

        string T="";
        for(i;i<s.size();i++)
        {
            if(s[i]==' ') continue;
                T+=s[i];
        }
        M[T]=t;
    }

    while(cin>>s)
    {
        if(M[s]==x)
            cout<<"eh"<<endl;
        else
            cout<<M[s]<<endl;
    }




}
