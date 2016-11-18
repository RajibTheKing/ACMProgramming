#include<iostream>
#include<string>
#include<map>

using namespace std;


int main()
{
    int L, N;
    string sKey, sValue, sTemp;
    map<string, string> mp;
    while(cin>>L>>N)
    {
        mp.clear();
        for(int i=0;i<L;i++)
        {
            cin>>sKey>>sValue;
            mp[sKey] = sValue;
        }

        for(int i=0;i<N;i++)
        {
            cin>>sTemp;
            int len = sTemp.size();
            if(mp.find(sTemp)!=mp.end())
            {
                sTemp = mp[sTemp];
            }
            else if(sTemp[len-1] == 'y')
            {
                if(len<2)
                    sTemp+="s";
                else
                {
                    char c=sTemp[len-2];
                    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                        sTemp+="s";
                    else
                    {
                        sTemp[len-1] = 'i';
                        sTemp+="es";
                    }
                }
            }
            else if(sTemp[len-1] == 'o'||sTemp[len-1] == 's'||sTemp[len-1] == 'x')
            {
                sTemp+="es";
            }
            else if(sTemp[len-1]!='h')
            {
                sTemp+="s";
            }
            else
            {
                if(len<2)
                {
                    sTemp+="s";
                }
                else if(sTemp[len-2]=='c'|| sTemp[len-2]=='s')
                {
                    sTemp+="es";
                }
                else
                {
                    sTemp+="s";
                }
            }
            //cout<<"------------>";
            cout<<sTemp<<endl;


        }

    }
    return 0;
}

