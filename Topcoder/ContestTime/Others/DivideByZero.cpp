#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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


class DivideByZero {
public:
    int Div(int a, int b)
    {
        if(a<b) return (int) b/a;
        return (int) a/b;
    }

    vector<int> clculate(vector<int> n)
    {
        if(n.size()==1) return n;
        set<int> st;
        st.clear();
        for(int i=0;i<n.size();i++)
        {
            for(int j=i+1;j<n.size();j++)
            {
                st.insert(n[i]);
                st.insert(n[j]);
                int k = Div(n[i], n[j]);
                st.insert(k);
            }
        }
        n.clear();
        for(std::set<int>::iterator it = st.begin();it!=st.end();it++)
            n.push_back(*it);
        for(int i=0;i<n.size();i++)
            cout<<n[i]<<" ";
        cout<<endl;
        return n;
    }

	int CountNumbers(vector <int> numbers)
	{
	    int sz;
	    while(true)
        {
            sz = numbers.size();
            numbers = clculate(numbers);
            if(numbers.size()==sz) break;

        }
        return sz;

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	DivideByZero *obj;
	int answer;
	obj = new DivideByZero();
	clock_t startTime = clock();
	answer = obj->CountNumbers(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <int> p0;
	int p1;

	{
	// ----- test 0 -----
	int t0[] = {9,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {8,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {1,5,8,30,15,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 11;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {1,2,4,8,16,32,64};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	int t0[] = {6,2,18};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Little John has a piece of paper with some distinct integers written on it.
// You are given a vector <int> numbers.
// The elements of numbers are the numbers written on John's paper.
//
// John is now going to add some new numbers to his paper.
// While doing so, he will be using integer division.
// When doing integer division, we discard the fractional part of the result.
// In this problem, we will use "div" to denote integer division.
// For example, 15 div 5 = 3, and 24 div 5 = 4.
//
// John will repeat the following process:
// He will look at his paper and select two distinct numbers A and B such that A is greater than B.
// He will compute C = A div B.
// If C is not written on his paper yet, he will add it to the paper.
//
// The process will stop once there is no way for John to add a new number to his paper.
// Compute and return how many numbers will there be on John's paper at the end.
//
// DEFINITION
// Class:DivideByZero
// Method:CountNumbers
// Parameters:vector <int>
// Returns:int
// Method signature:int CountNumbers(vector <int> numbers)
//
//
// NOTES
// -The return value does not depend on the order in which John adds new numbers to his paper.
//
//
// CONSTRAINTS
// -numbers will contain between 1 and 100 elements, inclusive.
// -Each element of numbers will be between 1 and 100, inclusive.
// -The elements in numbers will be distinct.
//
//
// EXAMPLES
//
// 0)
// {9, 2}
//
// Returns: 3
//
// John starts with just 9 and 2 on his paper.
// He can add the number 4, because 9 div 2 = 4.
// After he adds the number 4, there will be no more numbers to add, because 9 div 4 = 2, and also 4 div 2 = 2.
// Thus, at the end John's paper will contain 3 numbers: 9, 2, and 4.
//
// 1)
// {8, 2}
//
// Returns: 3
//
//
//
// 2)
// {50}
//
// Returns: 1
//
// We only have one number. There isn't anything John can do.
//
// 3)
// {1, 5, 8, 30, 15, 4}
//
// Returns: 11
//
//
//
// 4)
// {1, 2, 4, 8, 16, 32, 64}
//
// Returns: 7
//
//
//
// 5)
// {6, 2, 18}
//
// Returns: 7
//
// Once John has a number on his paper, he can use it when producing new numbers.
// For example, in this case he can add 9 (computed as 18 div 2), and then add 1 (computed as 9 div 6).
// The numbers he will have at the end are 1, 2, 3, 4, 6, 9, and 18.
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
