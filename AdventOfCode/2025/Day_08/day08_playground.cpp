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

class Point3D
{
public:
    double x, y, z;

    Point3D(double x_val = 0, double y_val = 0, double z_val = 0)
        : x(x_val), y(y_val), z(z_val) {}
};

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

double get_distance(Point3D p1, Point3D p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

long long solve_part1(const vector<Point3D>& points, const int pairs_to_process)
{
    long long result = 0;
    map<int, int> group;
    group.clear();
    int group_id = 1;

    for (int i = 1; i <= pairs_to_process; ++i)
    {
        cout << "Processing pair #" << i << endl;
        int idx1, idx2;
        double closest_distance = numeric_limits<double>::max();

        for (int a = 0; a < points.size(); ++a)
        {
            for (int b = 0; b < points.size(); ++b)
            {
                if (a == b) continue;
                if (group.find(a) != group.end() && group.find(b) != group.end() && group[a] == group[b])
                {
                    continue; // same group, skip
                }

                double dist = get_distance(points[a], points[b]);
                if (dist < closest_distance)
                {
                    closest_distance = dist;
                    idx1 = a;
                    idx2 = b;
                }
            }
        }

        cout << "Closest distance after iteration " << i << " is " << closest_distance << " between points " << points[idx1].x << "," << points[idx1].y << "," << points[idx1].z << " and " << points[idx2].x << "," << points[idx2].y << "," << points[idx2].z << endl;
        // Assign groups
        if (group.find(idx1) == group.end() && group.find(idx2) == group.end())
        {
            group[idx1] = group_id;
            group[idx2] = group_id;
            group_id++;
        }
        else if (group.find(idx1) != group.end() && group.find(idx2) == group.end())
        {
            group[idx2] = group[idx1];
        }
        else if (group.find(idx1) == group.end() && group.find(idx2) != group.end())
        {
            group[idx1] = group[idx2];
        }
        else
        {
            int old_group = group[idx2];
            int new_group = group[idx1];
            for (auto& entry : group)
            {
                if (entry.second == old_group)
                {
                    entry.second = new_group;
                }
            }
        }
    }

    // iterate through group map
    int group_count[1000];
    memset(group_count, 0, sizeof(group_count));
    for (const auto& entry : group)
    {
        group_count[entry.second]++;
    }
    for (int i = 1; i < pairs_to_process; ++i)
    {
       cout << "Group " << i << " has " << group_count[i] << " points." << endl;
    }
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
    vector<Point3D> points;
    int pairs_to_process = 0;

    for (int kase = 1; kase <= testCases; ++kase)
    {
        cout << "Processing test case #" << kase << endl;
        points.clear();
        while(getline(input, line) && !line.empty())
        {
            vector<string> coords = split(line, ',');
            if (coords.size() == 3)
            {
                double x = stod(coords[0]);
                double y = stod(coords[1]);
                double z = stod(coords[2]);
                points.emplace_back(x, y, z);
            }
            else{
                pairs_to_process = stoi(coords[0]);
            }
        }
        long long part1_result = solve_part1(points, pairs_to_process);
        cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        // long long part2_result = solve_part2(input_lines);
        // cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}