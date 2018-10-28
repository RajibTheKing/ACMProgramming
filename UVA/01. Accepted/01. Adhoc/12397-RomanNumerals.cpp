#include <iostream>
#include <vector>
using namespace std;

string getRomanValue(int n)
{
	if(n == 1) return "I";
	if(n == 4) return "IV";
	if(n == 5) return "V";
	if(n == 9) return "IX";
	if(n == 10) return "X";
	if(n == 40) return "XL";
	if(n == 50) return "L";
	if(n == 90) return "XC";
	if(n == 100) return "C";
	if(n == 400) return "CD";
	if(n == 500) return "D";
	if(n == 900) return "CM";
	if(n == 1000) return "M";

	return "";
}
int getMatchStickNumber(char c)
{
	if(c == 'I') return 1;
	if(c == 'V' || c == 'X' || c == 'L' || c == 'C') return 2;
	if(c == 'D') return 3;
	if(c == 'M') return 4;

	return -1;
}
int main()
{
	int n;
	vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	while(cin>>n)
	{
		string ans = "";
		int Quotient, Remainder;
		for(int i=0; i<vals.size(); i++)
		{
			if(vals[i] > n) continue;
			Quotient = n / vals[i]; 
			Remainder = n % vals[i];
			for(int j=0; j<Quotient; j++)
				ans+=getRomanValue(vals[i]);
			n = Remainder;
		}

		int KountSticks = 0;
		for(int i=0; i<ans.size(); i++)
		{
			KountSticks += getMatchStickNumber(ans[i]);
		}


		cout<<KountSticks<<endl;
	}

	return 0;
}