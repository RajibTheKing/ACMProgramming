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


long long solve_part1(const vector<string>& input_lines)
{
    // Implement the logic for part 1 here
    long long result = 0;
    vector<vector<long long>> numbers;
    numbers.clear();
    for (int i = 0; i < input_lines.size() - 1; ++i)
    {
        const string& line = input_lines[i];

        istringstream iss(line);
        vector<long long> row;
        long long num;
        while (iss >> num)
        {
            row.push_back(num);
        }
        numbers.push_back(row);

    }
    vector<char> operators;
    const string& ops_line = input_lines.back();
    istringstream ops_iss(ops_line);
    char op;
    while (ops_iss >> op)
    {
        operators.push_back(op);
    }

    for (int j = 0; j < operators.size(); ++j)
    {
        char current_op = operators[j];
        long long current_result = numbers[0][j];
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (current_op == '+')
            {
                current_result += numbers[i][j];
            }
            else if (current_op == '*')
            {
                current_result *= numbers[i][j];
            }
        }
        result += current_result;
    }
    return result;
}

long long solve_part2(const vector<string>& input_lines)
{
    // Implement the logic for part 2 here
    long long result = 0;
    vector<char> operators;
    const string& ops_line = input_lines.back();
    istringstream ops_iss(ops_line);
    char op;
    while (ops_iss >> op)
    {
        operators.push_back(op);
    }

    int current_col_index = 0;
    for (int j = 0; j < operators.size(); ++j)
    {
        char current_op = operators[j];
        long long current_result = -1;
        while (current_col_index < input_lines[0].size())
        {
            long long currentNumber = 0;
            for (int i = 0; i < input_lines.size() - 1; ++i)
            {
                if (input_lines[i][current_col_index] != ' ')
                {
                    currentNumber = currentNumber * 10 + input_lines[i][current_col_index] - '0';
                }
            }
            current_col_index++;
            if (currentNumber == 0)
            {
                break;
            }
            cout << "Current Number: " << currentNumber << endl;

            if (current_result == -1)
            {
                current_result = currentNumber;
            }
            else
            {
                if (current_op == '+')
                {
                    current_result += currentNumber;
                }
                else if (current_op == '*')
                {
                    current_result *= currentNumber;
                }
            }
        }
        result += current_result;
    }
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
        // long long part1_result = solve_part1(input_lines);
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = solve_part2(input_lines);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}