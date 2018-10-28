#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

bool isLeapYear(int y)
{
	if(y%400 == 0) return true;

	if(y%100 == 0) return false;

	if(y%4 == 0) return true;

	return false;
}
int strMonthToIntMonth(string s)
{
	if(s == "January") return 1;
	if(s == "February") return 2;
	if(s == "March") return 3;
	if(s == "April") return 4;
	if(s == "May") return 5;
	if(s == "June") return 6;
	if(s == "July") return 7;
	if(s == "August") return 8;
	if(s == "September") return 9;
	if(s == "October") return 10;
	if(s == "November") return 11;
	if(s == "December") return 12;
	return -1;
}
int strDayToIntDay(string s)
{
	string temp="";
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == ',') break;
		temp+=s[i];
	}

	int day;
	stringstream ss;
	ss.clear();
	ss<<temp;
	ss>>day;
	return day;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int T, kase = 0;
	cin>>T;
	string d1,d2, m1, m2;
	int y1, y2;
	int day, month;
	while(T--)
	{
		cin>>m1>>d1; cin>>y1;
		cin>>m2>>d2; cin>>y2;
		int start = y1;
		int end = y2;
		int kount = 0;
		
		if(strMonthToIntMonth(m1) > 2) start++;
		if(strMonthToIntMonth(m2) < 2 || (strMonthToIntMonth(m2) == 2 && strDayToIntDay(d2)<29)) end--;

		/*
		int diff = end - start + 1;
		int totaLeapYears = diff / 4;
		totaLeapYears -= (diff/100);
		totaLeapYears += (diff/400);
		kount = totaLeapYears;
		*/

		kount = end / 4 - (start - 1) / 4;
		kount -= end / 100 - (start - 1) / 100;
		kount += end / 400 - (start - 1) / 400;

		printf("Case %d: %d\n", ++kase, kount);

	}
	return 0;
}


