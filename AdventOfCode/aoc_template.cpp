#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

long long solve_part1(const vector<string>& input_lines)
{
    long long result = 0;
    // ...
    return result;
}

long long solve_part2(const vector<string>& input_lines)
{
    long long result = 0;
    // ...
    return result;
}

int main()
{
    ifstream input("input.txt");
    string line;
    getline(input, line);
    int testCases = stoi(line);

    for (int kase = 1; kase <= testCases; ++kase)
    {
        cout << "Processing test case #" << kase << endl;
        vector<string> input_lines;
        while(getline(input, line) && !line.empty())
        {
            input_lines.push_back(line);
        }
        long long part1_result = solve_part1(input_lines);
        cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = solve_part2(input_lines);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}