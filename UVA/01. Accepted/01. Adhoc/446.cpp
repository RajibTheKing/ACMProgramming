#include <iostream>
using namespace std;
string hexToBinary(char c)
{
	if(c == '0') return "0000";
	if(c == '1') return "0001";
	if(c == '2') return "0010";
	if(c == '3') return "0011";
	if(c == '4') return "0100";
	if(c == '5') return "0101";
	if(c == '6') return "0110";
	if(c == '7') return "0111";
	if(c == '8') return "1000";
	if(c == '9') return "1001";
	if(c == 'A') return "1010";
	if(c == 'B') return "1011";
	if(c == 'C') return "1100";
	if(c == 'D') return "1101";
	if(c == 'E') return "1110";
	if(c == 'F') return "1111";

	return "";
}
int binaryToInt(string str)
{
	int fact = 1;
	int res = 0;
	for(int i= str.size() - 1; i>=0; i--)
	{
		if(str[i] == '1')
			res+=fact;
		fact*=2;

	}
	return res;
}
string updateBinary(string str)
{
	while(str.size()<13)
	{
		str = "0"+str;
	}
	return str;
}
int main()
{
	int n;
	cin>>n;
	string hex1, sgn, hex2;
	string bin1, bin2;
	while(n--)
	{
		cin>>hex1>>sgn>>hex2;
		bin1 = "";
		for(int i=0; i<hex1.size(); i++)
		{
			bin1+=hexToBinary(hex1[i]);
		}
		bin2 = "";
		for(int i=0; i<hex2.size(); i++)
		{
			bin2+=hexToBinary(hex2[i]);
		}
		bin1 = updateBinary(bin1);
		bin2 = updateBinary(bin2);
		if(sgn == "+")
			cout<<bin1<<" "<<sgn<<" "<<bin2<<" = "<<binaryToInt(bin1) + binaryToInt(bin2)<<endl;
		else
			cout<<bin1<<" "<<sgn<<" "<<bin2<<" = "<<binaryToInt(bin1) - binaryToInt(bin2)<<endl;

	}
	return 0;
}