#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <numeric>
#include <functional>
#include <bitset>
#include <queue>
#include <stack>
#include <cstring>
#include <array>
#include <tuple>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cctype>
#include <locale>
#include <iterator>
#include <random>
#include <chrono>
#include <thread>
#include <filesystem>
#include <optional>
#include <variant>
#include <memory>
#include <type_traits>
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