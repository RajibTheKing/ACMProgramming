#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


int firstDayofNewYearAndMonth (int );
int numOfDaysInAMonth (int);
void printHeader (int);
int printMonth (int, int&, int);
void skipToDay (int);
void PrintAnswer(int);

int main ()
{

    int year=2011, firstDayInCurrentMonth, startingDay;
    int currentMonth;
    int numDays;
    startingDay=firstDayofNewYearAndMonth(year);

    int T;
    cin>>T;
    int MM, DD;
    while(T--)
    {
        cin>>MM>>DD;
        currentMonth = 1;
        firstDayInCurrentMonth = startingDay;
        while (currentMonth <= 12)
        {
            numDays = numOfDaysInAMonth(currentMonth);
            //printHeader(currentMonth);
            int ans = printMonth(numDays, firstDayInCurrentMonth, DD);
            //cout<<"Here: ans = "<<ans<<", currentMonth = "<<currentMonth<<endl;
            if(currentMonth == MM)
            {
                //cout<<ans<<endl;
                PrintAnswer(ans);
                break;
            }
            currentMonth = currentMonth + 1;
        }
    }

    return 0;
}

/**************************************************************************/
/* This function calculates the first day of the new year                 */
/**************************************************************************/

int  firstDayofNewYearAndMonth(int year)
{
    int day_start;
    int x1, x2, x3;
    x1 = (year - 1)/ 4;
    x2 = (year - 1)/ 100;
    x3 = (year - 1)/ 400;
    day_start = (year + x1 - x2 + x3) %7;
    return day_start;
}

/**************************************************************************/
/* This function returns the number of days in a month                    */
/**************************************************************************/

int numOfDaysInAMonth (int m)
{
    if (m == 1)
        return(31);
    else if (m == 2)
        return(28);
    else if (m == 3)
        return(31);
    else if (m == 4)
        return(30);
    else if (m == 5)
        return(31);
    else if (m == 6)
        return(30);
    else if (m == 7)
        return(31);
    else if (m == 8)
        return(31);
    else if (m == 9)
        return(30);
    else if (m == 10)
        return(31);
    else if (m == 11)
        return(30);
    else if (m == 12)
        return(31);
}

/**************************************************************************/
/*    It takes the number of the month and prints outs the name of the    */
/*  month and the frame of the calander                                   */
/**************************************************************************/

void printHeader (int m)
{
    if (m == 1)
    {

        cout << "January" << endl;
    }
    else if (m == 2)
    {
        cout << "February" << endl;
    }
    else if (m == 3)
    {
        cout << "March" << endl;
    }
    else if (m == 4)
    {
        cout << "April" << endl;
    }
    else if (m == 5)
    {
        cout << "May" << endl;
    }
    else if (m == 6)
    {
        cout << "June" << endl;
    }
    else if (m == 7)
    {
        cout << "July" << endl;
    }
    else if (m == 8)
    {
        cout << "August" << endl;
    }
    else if (m == 9)
    {
        cout << "September" << endl;
    }
    else if (m == 10)
    {
        cout << "October" << endl;
    }
    else if (m == 11)
    {
        cout << "November" << endl;
    }
    else if (m == 12)
    {
        cout << "December" << endl;
    }


    cout << " S  M  T  W  T  F  S" <<endl;
    cout << "_____________________" << endl;
}

/**************************************************************************/
/* Helps with the skipToDay function blah blah blah                       */
/**************************************************************************/

void skip (int i)
{
    while (i > 0)
    {
        cout << " ";
        i = i - 1;
    }
}
/**************************************************************************/
/* This function prints out the days in the month after the header for    */
/* each month                                                             */
/**************************************************************************/

int printMonth (int numDays, int &weekDay, int forDay)
{
    int day = 1;
    //skipToDay(weekDay);
    int ans = -1;
    while (day <= numDays)
    {
        //cout << setw(2) << day << " ";
        if(day == forDay)
        {
            ans = weekDay;
        }
        if (weekDay == 6)
        {
            //cout << endl;
            weekDay = 0;
        }
        else weekDay = weekDay + 1;
        day = day + 1;
    }
    return ans;
}

/**************************************************************************/
/* Prints spaces in monthly calander                                      */
/**************************************************************************/

void skipToDay (int d)
{
    return skip(3*d);
}

void PrintAnswer(int a)
{
    switch(a)
    {
    case 4:
        cout<<"Thursday"<<endl;
        break;
    case 5:
        cout<<"Friday"<<endl;
        break;
    case 6:
        cout<<"Saturday"<<endl;
        break;
    case 0:
        cout<<"Sunday"<<endl;
        break;
    case 1:
        cout<<"Monday"<<endl;
        break;
    case 2:
        cout<<"Tuesday"<<endl;
        break;
    case 3:
        cout<<"Wednesday"<<endl;
        break;

    }
}
