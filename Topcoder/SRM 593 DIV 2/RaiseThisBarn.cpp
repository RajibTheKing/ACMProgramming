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


class RaiseThisBarn {
public:
    string s;
    bool check(int k)
    {
        int s1=0, s2=0;
        for(int i=0;i<k;i++)
            if(s[i]=='c') s1++;

        for(int i=k;i<s.size();i++)
            if(s[i]=='c') s2++;
        if(s1==s2) return true;
        return false;

    }
	int calc(string str)
	{
	    s=str;
	    int kount=0;
	    for(int i=1;i<str.size();i++)
        {
            if(check(i)) kount++;
        }
        return kount;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	RaiseThisBarn *obj;
	int answer;
	obj = new RaiseThisBarn();
	clock_t startTime = clock();
	answer = obj->calc(p0);
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

	string p0;
	int p1;

	{
	// ----- test 0 -----
	p0 = "cc..c.c";
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "c....c....c";
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "............";
	p1 = 11;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = ".c.c...c..ccc.c..c.c.cc..ccc";
	p1 = 3;
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
// The pony Applejack is going to raise a new barn.
// The barn will consist of N sections in a row.
// Some of the sections will be empty, others will contain a single cow each.
// You are given a string str with N characters.
// This string describes the desired layout of the barn:
// the character 'c' represents a section with a cow, and the character '.' represents an empty section.
//
// After she raises the barn, Applejack will build a wall that will divide the barn into two separate parts:
// one containing the first k sections and the other containing the last N-k sections, for some integer k.
// Each part must contain at least one section. (I.e., k must be between 1 and N-1, inclusive.)
// Additionally, Applejack wants both parts to contain exactly the same number of cows.
//
// Return the number of possible positions for the wall.
// In other words, return the number of choices for the integer k such that all the conditions above are satisfied.
//
// DEFINITION
// Class:RaiseThisBarn
// Method:calc
// Parameters:string
// Returns:int
// Method signature:int calc(string str)
//
//
// CONSTRAINTS
// -str will contain between 2 and 50 characters, inclusive.
// -Each character in str will be 'c' or '.'.
//
//
// EXAMPLES
//
// 0)
// "cc..c.c"
//
// Returns: 3
//
// Applejack can choose k=2, k=3, or k=4.
// The three corresponding solutions are shown below, with '|' representing the wall between the two parts.
//
// cc|..c.c
// cc.|.c.c
// cc..|c.c
//
//
// 1)
// "c....c....c"
//
// Returns: 0
//
// There is an odd number of cows. It is impossible to divide them into two equal halves.
//
// 2)
// "............"
//
// Returns: 11
//
// This is a barn with 12 empty sections. It can be divided in 11 different ways: into 1+11 sections, 2+10 sections, ..., or 11+1 sections.
//
// 3)
// ".c.c...c..ccc.c..c.c.cc..ccc"
//
// Returns: 3
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
