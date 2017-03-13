#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
string rearrange(string a)
{
    string t1, t2;
    int i;
    t2="";
    for(i=a.size()-1;i>=0;i--)
        t2+=a[i];
    return t2;
}

string find_alpha(int dd)
{
    string ans="";
    while(dd)
    {
        dd-=1;

        ans+=(dd)%26 + 'A';
        dd/=26;
    }

    return rearrange(ans);
}
int find_number(string ss)
{
    int ans=0;
    for(int i=0;i<ss.size();i++)
    {
        ans*=26;
        ans+=ss[i]-'A'+1;
    }

    return ans;
}

main()
{
    stringstream ss;
    int n, num1, num2, i;
    string a;
    bool f1, f2;
    char c,d;
    cin>>n;
    while(n--)
    {
        cin>>a;
        int k;
        k=a.size();
        f1=false;
        f2=false;

        for( i=0;i<k;i++)
        {
            if(a[i]>='0'&&a[i]<='9'&&f1==false)
                f1=true;

            if(a[i]>='A'&&a[i]<='Z'&&f1==true)
                f2=true;

        }

        if(f1==true&&f2==true)
        {
            ss.clear();
            ss<<a;
            ss>>c>>num1>>d>>num2;
            cout<<find_alpha(num2)<<num1<<endl;

        }
        else
        {
            string temp="";

            for(i=0;i<k;i++)
            {
                if(a[i]>='A'&&a[i]<='Z')
                    temp+=a[i];
                else
                    break;
            }

            num2=find_number(temp);

            temp="";
            for(i;i<k;i++)
                temp+=a[i];
            ss.clear();
            ss<<temp;
            ss>>num1;


            printf("R%dC%d\n", num1, num2);
        }
    }
}
