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


class LongLongTripDiv2 {
public:
	string isAble(long long D, int T, int B)
	{
	     double d = D, t=T, b=B;

	    double hel = d/b*1.0;

	    if(hel>t) return "Impossible";

        if((D-T)%(B-1)!=0) return "Impossible";

        if(D-T<0) return "Impossible";

        return "Possible";


	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, long long p0, int p1, int p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	LongLongTripDiv2 *obj;
	string answer;
	obj = new LongLongTripDiv2();
	clock_t startTime = clock();
	answer = obj->isAble(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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

	long long p0;
	int p1;
	int p2;
	string p3;

	{
	// ----- test 0 -----
	p0 = 10ll;
	p1 = 6;
	p2 = 3;
	p3 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 10ll;
	p1 = 5;
	p2 = 3;
	p3 = "Impossible";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 50ll;
	p1 = 100;
	p2 = 2;
	p3 = "Impossible";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 120ll;
	p1 = 10;
	p2 = 11;
	p3 = "Impossible";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 10ll;
	p1 = 10;
	p2 = 9999;
	p3 = "Possible";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 1000ll;
	p1 = 100;
	p2 = 10;
	p3 = "Possible";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = 1000010000100001ll;
	p1 = 1100011;
	p2 = 1000000000;
	p3 = "Possible";
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
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
// Limit is a flea. He can do two types of jumps: small jumps that have length 1 millimeter, and big jumps that have length B millimeters.
//
// Limit is going to make exactly T jumps, all of them in the same direction. He would like to travel exactly D millimeters in those jumps. Is this possible?
//
// You are given a long long D, and ints T and B. Return "Possible" (quotes for clarity) if there is a combination of T jumps forward that has a total length of exactly D millimeters. Otherwise, return "Impossible".
//
// DEFINITION
// Class:LongLongTripDiv2
// Method:isAble
// Parameters:long long, int, int
// Returns:string
// Method signature:string isAble(long long D, int T, int B)
//
//
// CONSTRAINTS
// -D will be between 1 and 10^18, inclusive.
// -T will be between 1 and 1,000,000,000, inclusive.
// -B will be between 2 and 1,000,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 10
// 6
// 3
//
// Returns: "Possible"
//
// Limit must make 6 jumps that have a total length of 10 millimeters. This is possible: two of the jumps must be long and the other four must be short.
//
// 1)
// 10
// 5
// 3
//
// Returns: "Impossible"
//
//
//
// 2)
// 50
// 100
// 2
//
// Returns: "Impossible"
//
//
//
// 3)
// 120
// 10
// 11
//
// Returns: "Impossible"
//
//
//
// 4)
// 10
// 10
// 9999
//
// Returns: "Possible"
//
//
//
// 5)
// 1000
// 100
// 10
//
// Returns: "Possible"
//
//
//
// 6)
// 1000010000100001
// 1100011
// 1000000000
//
// Returns: "Possible"
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
