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
    vector<string> ranges;
    long long result = 0;
    for (const auto& line : input_lines)
    {
        // Split the line by comma
        stringstream ss(line);
        string item;
        while (getline(ss, item, ','))
        {
            ranges.push_back(item);
        }
    }

    for (const auto& range : ranges)
    {
        stringstream ss(range);
        string start_str, end_str;
        getline(ss, start_str, '-');
        getline(ss, end_str, '-');
        long long start = stoll(start_str);
        long long end = stoll(end_str);
        cout << "Processing range: " << start << " to " << end << endl;
        for (long long i = start; i <= end; ++i)
        {
            string num_gets = to_string(i);
            for (int j = 0; j < num_gets.size(); ++j)
            {
                string firstPart = num_gets.substr(0, j);
                string secondPart = num_gets.substr(j);
                if(firstPart == secondPart)
                {
                    result+= i;
                    cout << "Found matching split: " << num_gets << " -> " << firstPart << " | " << secondPart << " CurrentResult: " << result << endl;
                }
            }
        }
    }
    return result;
}
bool isRepeatableByStep(int step, const string& num_gets)
{
    if (num_gets.size() % step != 0)
    {
        return false;
    }
    for (size_t i = 0; i < num_gets.size(); i += step)
    {
        string segment = num_gets.substr(i, step);
        for (size_t j = i + step; j < num_gets.size(); j += step)
        {
            string nextSegment = num_gets.substr(j, step);
            if (segment != nextSegment)
            {
                return false;
            }
        }
    }
    return true;
}
bool isInvalid(string num_gets)
{
    // check if all digitst are the same
    for (int i = 1; i<num_gets.size(); ++i)
    {
        if (isRepeatableByStep(i, num_gets))
        {
            return true;
        }
    }
    return false;
}

long long solve_part2(const vector<string>& input_lines)
{
    vector<string> ranges;
    long long result = 0;
    for (const auto& line : input_lines)
    {
        // Split the line by comma
        stringstream ss(line);
        string item;
        while (getline(ss, item, ','))
        {
            ranges.push_back(item);
        }
    }

    for (const auto& range : ranges)
    {
        stringstream ss(range);
        string start_str, end_str;
        getline(ss, start_str, '-');
        getline(ss, end_str, '-');
        long long start = stoll(start_str);
        long long end = stoll(end_str);
        cout << "Processing range: " << start << " to " << end << endl;
        for (long long i = start; i <= end; ++i)
        {
            string num_gets = to_string(i);
            if(isInvalid(num_gets))
            {
                // cout << "Checking number: " << num_gets << " isInvalid: " << isInvalid(num_gets) << endl;
                result+=i;
            }
        }
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
            // Process each line of the test case
            cout << "Processing line: " << line << endl;
            input_lines.push_back(line);
        }
        // long long part1_result = solve_part1(input_lines);
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = solve_part2(input_lines);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}