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


class LittleElephantAndPermutationDiv2 {
public:
    int fact(int n)
    {
        int ans = 1;
        for(int i=1;i<=n;i++)
            ans *=i;
        return ans;

    }
	long long getNumber(int N, int K)
	{
	    long long kount = 0;
	    vector<int> numbers;
	    for(int i=1;i<=N;i++) numbers.push_back(i);
	    do
        {
            int sum = 0;
            for(int i=1;i<=N;i++)
                sum+=max(i, numbers[i-1]);
            if(sum>=K) kount++;

        }while(next_permutation(numbers.begin(), numbers.end()));
        return kount*fact(N);


	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	LittleElephantAndPermutationDiv2 *obj;
	long long answer;
	obj = new LittleElephantAndPermutationDiv2();
	clock_t startTime = clock();
	answer = obj->getNumber(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	int p1;
	long long p2;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 1;
	p2 = 4ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 8;
	p2 = 18ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 47;
	p2 = 13168189440000ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
//
// This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.
//
//
//
//
// Little Elephant from the Zoo of Lviv likes permutations.
// A permutation of size N is a sequence (a1, ..., aN) that contains each of the numbers from 1 to N exactly once.
// For example, (3,1,4,5,2) is a permutation of size 5.
//
//
//
//
// Given two permutations A = (a1, ..., aN) and B = (b1, ..., bN), the value magic(A,B) is defined as follows:
// magic(A,B) = max(a1,b1) + max(a2,b2) + ... + max(aN,bN).
//
//
//
//
// You are given the int N.
// You are also given another int K.
// Return the number of pairs (A,B) such that both A and B are permutations of size N, and magic(A,B) is greater than or equal to K.
// (Note that A and B are not required to be distinct.)
//
//
// DEFINITION
// Class:LittleElephantAndPermutationDiv2
// Method:getNumber
// Parameters:int, int
// Returns:long long
// Method signature:long long getNumber(int N, int K)
//
//
// CONSTRAINTS
// -N will be between 1 and 10, inclusive.
// -K will be between 1 and 100, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
// 1
//
// Returns: 1
//
// For N=1 the only pair of permutations is ( (1), (1) ).
// The magic of this pair of permutations is 1, so we count it.
//
// 1)
// 2
// 1
//
// Returns: 4
//
// Now there are four possible pairs of permutations. They are shown below, along with their magic value.
//
// magic( (1,2), (1,2) ) = 1+2 = 3
// magic( (1,2), (2,1) ) = 2+2 = 4
// magic( (2,1), (1,2) ) = 2+2 = 4
// magic( (2,1), (2,1) ) = 2+1 = 3
//
// In all four cases the magic value is greater than or equal to K.
//
// 2)
// 3
// 8
//
// Returns: 18
//
// When A = (1,2,3), there are 3 possibilities for B: (2,3,1), (3,1,2) and (3,2,1). For each of the other 5 values of A, it can be shown that there are 3 possibilities for B as well. Therefore the answer is 3*6 = 18.
//
// 3)
// 10
// 47
//
// Returns: 13168189440000
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
