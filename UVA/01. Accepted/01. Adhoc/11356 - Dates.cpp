#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
string Month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
bool isLeapYear(int y)
{
    if(y%400==0) return true;
    else if(y%100==0) return false;
    else if(y%4==0) return true;
    else return false;

}
int NumberOfDay(int year, int month)
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
    if(month==4||month==6||month==9||month==11) return 30;
    if(month==2 && isLeapYear(year)) return 29;
    if(month==2 && !isLeapYear(year)) return 28;

}
int MonthID(string s)
{

    for(int i=0;i<12;i++)
        if(Month[i]==s) return i+1;
    return -1;

}



vector<string> SplitString(string s, char delimiter)
{
    vector<string> result;
    string token;
    stringstream ss(s);
    while(getline(ss,token,delimiter))
    {
        result.push_back(token);
    }
    return result;
}


void FindAnswer(int year, int month, int day, int dif)
{
    int kounter=-1;
    for(year;year<=3000;year++)
    {
        for(month;month<=12;month++)
        {
            for(day;day<=NumberOfDay(year,month);day++)
            {
                kounter++;
                if(kounter==dif)
                {
                    //cout<<year<<" "<<month<<" "<<day<<endl;
                    cout<<year<<"-"<<Month[month-1]<<"-";
                    printf("%02d\n", day);

                    return;
                }

            }
            day=1;
        }
        month=1;

    }
}
int main()
{

    int T, dif, year, month, day, kase=0;
    string s;
    cin>>T;
    while(T--)
    {
        cin>>s;
        cin>>dif;
        vector<string> str = SplitString(s,'-');
        stringstream ss;
        ss.clear();
        ss<<str[0];
        ss>>year;

        month = MonthID(str[1]);

        ss.clear();
        ss<<str[2];
        ss>>day;

        cout<<"Case "<<(++kase)<<": ";
        FindAnswer(year,month,day,dif);



    }


    return 0;
}
