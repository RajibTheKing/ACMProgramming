#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>

#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    int ans1, ans2;
    int arr[2005];
    map<int,int> mp;
    int dol, ps;
    while(cin>>dol>>ps)
    {
        mp.clear();
        for(int i=1;i<=ps;i++)
        {
            mp[i]=0;
        }

        for(int i=0;i<dol;i++)
        {
            cin>>arr[i];

            if(arr[i]<=ps)
                mp[arr[i]]++;

        }

        ans1 = dol/ps;
        int swapOperation = 0;

        for(int i=0;i<dol;i++)
        {
            if(arr[i]>ps)
            {
                for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
                {
                    //cout<<it->first<<", "<<it->second<<endl;
                    if(it->second < ans1)
                    {
                        arr[i]=it->first;
                        it->second++;
                        swapOperation++;
                        break;
                    }
                    else if(it->second>ans1)
                    {
                        arr[i]=it->first;
                        it->second--;
                        swapOperation++;
                        break;

                    }


                }
            }
        }


        for(int i=0;i<dol;i++)
        {
            if(arr[i]>ps)
            {
                for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
                {
                    //cout<<it->first<<", "<<it->second<<endl;
                    if(it->second < ans1)
                    {
                        arr[i]=it->first;
                        it->second++;
                        swapOperation++;
                        break;
                    }
                    else if(it->second>ans1)
                    {
                        arr[i]=it->first;
                        it->second--;
                        swapOperation++;
                        break;

                    }


                }
            }
        }



        cout<<ans1<<" "<<swapOperation<<endl;

        for(int i=0;i<dol;i++)
        {

            if(i)
                cout<<" "<<arr[i];
            else
                cout<<arr[i];

        }
        cout<<endl;


    }

    return 0;

}
