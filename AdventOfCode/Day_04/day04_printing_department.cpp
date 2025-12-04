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


int solve_part1(const vector<string>& input_lines)
{
    // Implement the logic for part 1 here
    int result = 0;
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int row = input_lines.size();
    int col = input_lines[0].size();
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (input_lines[i][j] == '@')
            {
                // check all 8 directions
                int countAdj = 0;
                for (int dir = 0; dir < 8; ++dir)
                {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni >= 0 && ni < row && nj >= 0 && nj < col)
                    {
                        if (input_lines[ni][nj] == '@')
                        {
                            countAdj++;
                        }
                    }
                }
                if (countAdj < 4)
                {
                    result++;
                }
            }
        }
    }
    return result;
}

int solve_part2(vector<string>& input_lines)
{
     // Implement the logic for part 1 here
    int result = 0;
    int totalRemoved = 0;
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int row = input_lines.size();
    int col = input_lines[0].size();
    bool color[150][150];
    while(true)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                color[i][j] = false;
            }
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (input_lines[i][j] == '@')
                {
                    // check all 8 directions
                    int countAdj = 0;
                    for (int dir = 0; dir < 8; ++dir)
                    {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if (ni >= 0 && ni < row && nj >= 0 && nj < col)
                        {
                            if (input_lines[ni][nj] == '@')
                            {
                                countAdj++;
                            }
                        }
                    }
                    if (countAdj < 4)
                    {
                        color[i][j] = true;
                        result++;
                    }
                }
            }
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (color[i][j])
                {
                    input_lines[i][j] = '.';
                }
            }
        }
        totalRemoved += result;
        if (result == 0)
        {
            break;
        }
        result = 0;
    }

    return totalRemoved;
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
        // int part1_result = solve_part1(input_lines);
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        int part2_result = solve_part2(input_lines);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}