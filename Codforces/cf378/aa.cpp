#include<iostream>
#include<map>



using namespace std;

map<int, int> mp;

int main()
{
    mp.clear();
    mp[12] = 10;
    mp[13] = 12;
    mp[9] = 18;
    mp[45] = 18;
    mp[11] = 18;
    mp[10] = 18;
    for(map<int,int>::iterator it = mp.begin(); it!=mp.end(); it++)
    {
        cout<<it->first<<endl;
    }
    return 0;
}
