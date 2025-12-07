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

class Cafeteria
{
public:
    long long left, right;
    Cafeteria(long long left, long long right) : left(left), right(right) {}
    ~Cafeteria() {}
    bool isFresh(long long value) const {
        return value >= left && value <= right;
    }
};

bool CompareCafeteria(const Cafeteria& a, const Cafeteria& b)
{
    return a.left < b.left;
}

long long solve_part1(const vector<string>& ranges, const vector<string>& numbers)
{
    // Implement the logic for part 1 here
    long long result = 0;
    vector<Cafeteria> cafeterias;
    for (const auto& range_str : ranges) {
        stringstream ss(range_str);
        long long left, right;
        char dash;
        ss >> left >> dash >> right;
        Cafeteria cafeteria(left, right);
        cafeterias.push_back(cafeteria);
    }
    for (const auto& number_str : numbers) {
        long long number = stoll(number_str);
        for (const auto& cafeteria : cafeterias) {
            if (cafeteria.isFresh(number)) {
                result++;
                break;
            }
        }
    }
    return result;
}

long long solve_part2(const vector<string>& ranges)
{
    // Implement the logic for part 1 here
    long long result = 0;
    vector<Cafeteria> cafeterias;

    for (const auto& range_str : ranges) {
        stringstream ss(range_str);
        long long left, right;
        char dash;
        ss >> left >> dash >> right;
        Cafeteria cafeteria(left, right);
        cafeterias.push_back(cafeteria);
    }

    sort(cafeterias.begin(), cafeterias.end(), CompareCafeteria);

    // Merge overlapping ranges
    vector<Cafeteria> merged;
    long long current_left = cafeterias[0].left;
    long long current_right = cafeterias[0].right;
    for (size_t i = 1; i < cafeterias.size(); ++i) {
        if (cafeterias[i].left <= current_right) {
            current_right = max(current_right, cafeterias[i].right);
        } else {
            merged.emplace_back(current_left, current_right);
            current_left = cafeterias[i].left;
            current_right = cafeterias[i].right;
        }
    }
    merged.emplace_back(current_left, current_right);

    // count total fresh numbers
    for (const auto& cafeteria : merged) {
        result += (cafeteria.right - cafeteria.left + 1);
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
        vector<string> ranges, numbers;
        while(getline(input, line) && !line.empty())
        {
            ranges.push_back(line);
        }

        while(getline(input, line) && !line.empty())
        {
            numbers.push_back(line);
        }

        // int part1_result = solve_part1(ranges, numbers);
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = solve_part2(ranges);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}