#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isMatched(string s1, string s2)
{
	for(int i=0; i<s1.size(); i++)
		s1[i] = tolower(s1[i]);
	for(int i=0; i<s2.size(); i++)
		s2[i] = tolower(s2[i]);

	sort(&s1[0], &s1[s1.size()]);
	sort(&s2[0], &s2[s2.size()]);


	if(s1 == s2) return true;
	return false;
}

int main()
{
	string input;
	vector<string> inputList;
	set<string> st;
	while(cin>>input)
	{
		if(input == "#") break;
		inputList.push_back(input);

	}

	for(int i=0; i<inputList.size(); i++)
	{
		if(inputList[i].size()<=0) continue;

		bool flag = true;
		for(int j=i+1; j<inputList.size(); j++)
		{
			if(isMatched(inputList[i], inputList[j]))
			{
				flag = false;
				inputList[j] = "";		
			}
		}
		if(flag)
		{
			//cout<<"Intermediate: "<<input<<endl;
			st.insert(inputList[i]);
		}
	}

	for(auto it : st)
	{
		cout<<it<<endl;
	}

	return 0;
}
/*
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
*/


