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


class SilverbachConjecture {
public:
    bool isComposit(int a)
    {
        int kount=0;
        for(int i=1;i<=a;i++)
        {
            if(a%i==0) kount++;
            if(kount>2) return true;
        }
        if(kount>2) return true;
        return false;
    }

	vector <int> solve(int n)
	{
	    vector<int> cc;
	    cc.clear();

	    for(int i=1;i<=n;i++)
        {
            if(isComposit(i))
                cc.push_back(i);
        }

        vector<int> ans;
        ans.clear();

        for(int i=0;i<cc.size();i++)
        {
            bool flag=false;
            for(int j=0;j<cc.size();j++)
            {
                //if(i==j) continue;
                if((cc[i]+cc[j])==n)
                {
                    ans.push_back(cc[i]);
                    ans.push_back(cc[j]);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        return ans;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	SilverbachConjecture *obj;
	vector <int> answer;
	obj = new SilverbachConjecture();
	clock_t startTime = clock();
	answer = obj->solve(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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

	int p0;
	vector <int> p1;

	{
	// ----- test 0 -----
	p0 = 20;
	int t1[] = {8,12};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 30;
	int t1[] = {15,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 999;
	int t1[] = {699,300};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 45;
	int t1[] = {15,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// In this problem, some test cases have more than one correct output. We are using a special checker to verify that the output of your program is correct.
//
// A positive integer x is called composite if there are positive integers y > 1 and z > 1 such that x = yz.
// In other words, a composite positive integer has a positive integer divisor other than 1 and itself.
// For example, 48 is composite because 48 = 4*12.
// The smallest few composite integers are 4, 6, 8, 9, and 10.
//
// You are given an int n.
// Return a vector <int> with two elements.
// Both elements of the returned vector <int> must be positive composite integers, and their sum must be n.
//
// For the given constraints on n at least one such pair always exists.
// Note that if there are many such pairs, your solution can return any one of them.
//
// DEFINITION
// Class:SilverbachConjecture
// Method:solve
// Parameters:int
// Returns:vector <int>
// Method signature:vector <int> solve(int n)
//
//
// CONSTRAINTS
// -n will be between 20 and 2000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 20
//
// Returns: {8, 12 }
//
// For n=20 there are seven correct answers: {4,16}, {6,14}, {8,12}, {10,10}, {12,8}, {14,6}, and {16,4}. Your program must return one of these seven answers.
//
// 1)
// 30
//
// Returns: {15, 15 }
//
// You may return two identical numbers.
//
// 2)
// 999
//
// Returns: {699, 300 }
//
//
//
// 3)
// 45
//
// Returns: {15, 30 }
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!