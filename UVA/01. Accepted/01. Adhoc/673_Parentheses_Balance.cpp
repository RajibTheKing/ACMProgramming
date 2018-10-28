#include <iostream>
#include <string>
#include <stack>

#include <string.h>
using namespace std;

bool getAns(string input)
{
	stack<char> st;


	for(int j = 0; j < input.size(); j++)
	{
		char c = input[j];

		if(c == '(' || c == '[')
			st.push(c);
		else if ( c == ')')
		{
			if(!st.empty())
			{
				char check = st.top();
				if(check != '(') 
					return false;
				else
					st.pop();
			}
			else
				return false;
			

		}
		else if ( c == ']')
		{
			if(!st.empty())
			{
				char check = st.top();
				if(check != '[') 
					return false;
				else
					st.pop();
			}
			else
				return false;

		}
	}

	if(st.size() != 0) return false;

	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	string input;
	char inChar[1000];

	

	while(scanf("%d", &n) == 1)
	{
		getchar();

		for(int i=0; i<n; i++)
		{
			gets(inChar);
			input = "";
			for(int k=0; k<strlen(inChar); k++)
				input += inChar[k];

			bool ans = getAns(input);

			if(ans == false)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
	}	

	return 0;
}

/*


())
(()
*/

