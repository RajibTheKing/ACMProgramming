#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class LuckyCounter
{
    public:
	int countLuckyMoments(vector <string>);
};

int LuckyCounter::countLuckyMoments(vector <string> m)
{
    string a;
    char A[6];
    int ans=0;
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].length();j++)
        {
            A[j]=m[i][j];

        }
        if(A[0]==A[3] && A[1]==A[4])
            ans++;

        else if(A[0]==A[1]  && A[3]==A[4])
            ans++;

        else if(A[0]==A[4] && A[1]==A[3])
            ans++;
    }


    return ans;

}


//Powered by [KawigiEdit] 2.0!

//<%:start-tests%>
double test0() {
	string t0[] = {"12:21", "11:10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LuckyCounter * obj = new LuckyCounter();
	clock_t start = clock();
	int my_answer = obj->countLuckyMoments(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"00:00", "00:59", "23:00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LuckyCounter * obj = new LuckyCounter();
	clock_t start = clock();
	int my_answer = obj->countLuckyMoments(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"12:34"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LuckyCounter * obj = new LuckyCounter();
	clock_t start = clock();
	int my_answer = obj->countLuckyMoments(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LuckyCounter * obj = new LuckyCounter();
	clock_t start = clock();
	int my_answer = obj->countLuckyMoments(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
//<%:end-tests%>
int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

