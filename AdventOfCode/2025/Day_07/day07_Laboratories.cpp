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

long long solve_part1(vector<string>& input_lines)
{
    // Implement the logic for part 1 here
    long long result = 0;
    for (int i = 1; i < input_lines.size(); ++i)
    {
        for (int j = 0; j < input_lines[i].size(); ++j)
        {
            // Example processing logic
            if (input_lines[i-1][j] == 'S')
            {
                input_lines[i][j] = '|';
            }

            if (input_lines[i][j] == '^' && input_lines[i-1][j] == '|')
            {
                result += 1;
                input_lines[i][j-1] = '|';
                input_lines[i][j+1] = '|';
            }

            if (input_lines[i][j] == '.' && input_lines[i-1][j] == '|')
            {
                input_lines[i][j] = '|';
            }
        }
    }
    return result;
}

long long dp[160][160];

long long solve_part2(int row, int col, vector<string>& input_lines)
{
    // cout << "At position (" << row << ", " << col << ")\n";

    if (row >= input_lines.size() - 1 || col < 0 || col >= input_lines[row].size())
        return 1;

    if (input_lines[row + 1][col] == '.')
        return 1;

    long long &ret = dp[row][col];
    if (ret != -1) return ret;
    ret = 0;

    if (input_lines[row + 1][col] == '|')
    {
        ret += solve_part2(row + 1, col, input_lines);
    }
    else if (input_lines[row + 1][col] == '^')
    {
        // When we hit a ^, we branch to both left and right
        ret += solve_part2(row + 1, col - 1, input_lines);
        ret += solve_part2(row + 1, col + 1, input_lines);
    }
    else if (input_lines[row + 1][col] == 'S')
    {
        // Treat 'S' as continuation down
        ret += solve_part2(row + 1, col, input_lines);
    }
    return ret;
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
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;

        // reset dp array
        for (int i = 0; i < 160; ++i)
            for (int j = 0; j < 160; ++j)
                dp[i][j] = -1;

        // find the index of 'S' in the first line
        int start_index = -1;
        for (int j = 0; j < input_lines[0].size(); ++j)
        {
            if (input_lines[0][j] == 'S')
            {
                start_index = j;
                break;
            }
        }

        long long part2_result = solve_part2(0, start_index, input_lines);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}