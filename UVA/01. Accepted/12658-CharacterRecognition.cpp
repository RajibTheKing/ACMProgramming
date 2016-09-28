#include<iostream>
#include<string>
using namespace std;

string getInt(string str, int col)
{
    //cout<<"Hel: "<<str<<endl;
    if(str[col]=='.' && str[col+1]=='*' && str[col+2]=='.') return "1";
    if(str[col]=='*' && str[col+1]=='.' && str[col+2]=='.') return "2";
    if(str[col]=='.' && str[col+1]=='.' && str[col+2]=='*') return "3";

    return "";
}
int main()
{
    int n;
    string str[5];
    while(cin>>n)
    {
        int total = 4*n;
        for(int i=0;i<5;i++)
        {
            getline(cin, str[i]);

        }
        string ans="";

        for(int j=0;j<=total;j+=4)
        {
            ans+=getInt(str[4], j);
        }
        //cout<<"hello"<<endl;
        cout<<ans<<endl;

    }
}
