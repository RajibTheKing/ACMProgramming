#include <iostream>
#include <string>
#include <map>
#include <locale>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

string makeLower(string str)
{
	string ret = "";
	for(int i=0; i<str.size(); i++)
	{
		str[i] = tolower(str[i]);
		if(str[i]>='a' && str[i]<='z')
			ret+=str[i];
	}
	return ret;
}
string removeSpecials(string s)
{
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>='a' && s[i]<='z') continue;
		if(s[i]>='A' && s[i]<='Z') continue;
		s[i] = ' ';
	}
	return s;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int K, E, kase = 0;
	map<string, bool> mp;
	string keyword;
	string excuses[21];
	string excuse;
	int excuseCount[21];
	while(cin>>K>>E)
	{
		mp.clear();
		int maxcount = 0;
		memset(excuseCount, 0, sizeof(excuseCount));

		for(int i=0; i<K; i++)
		{
			cin>>keyword;
			mp[keyword] = true;
		}
		getchar();
		for(int i=0; i<E; i++)
		{
			getline(cin, excuses[i]);
			string tempExcuse = removeSpecials(excuses[i]); 
			//cout<<"Test1: "<<excuses[i]<<endl;
			stringstream ss;
			ss<<tempExcuse;
			while(ss>>excuse)
			{
				//cout<<"Test2: "<<excuse<<endl;
				if(mp[ makeLower(excuse) ] == true)
				{
					excuseCount[i]++ ;
				}
			}
			//cout<<"Test3: "<<excuseCount[i]<<endl;
			maxcount = max(maxcount, excuseCount[i]);

		}
		cout<<"Excuse Set #"<<(++kase)<<endl;
		for(int i=0; i<E; i++)
		{
			if(maxcount == excuseCount[i])
				cout<<excuses[i]<<endl;
		}
		cout<<endl;
	}

	return 0;
}