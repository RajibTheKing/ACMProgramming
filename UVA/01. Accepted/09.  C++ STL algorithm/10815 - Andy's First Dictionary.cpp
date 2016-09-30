#include<iostream>
#include<string>
#include<set>

using namespace std;


int main()
{
    //freopen("input.txt", "r", stdin);
    set<string> R;
    R.clear();
    string n, t;

    while(cin>>n)
    {
        t="";
        for(int i=0;i<=n.size();i++)
        {
            if(isalpha(n[i]))
                t+=tolower(n[i]);
            else if(t!="")
            {

                R.insert(t);
                t="";
            }

        }


    }
    for (std::set<string>::iterator it=R.begin(); it!=R.end();it++)
            cout<<*it<<endl;




    return 0;
}
