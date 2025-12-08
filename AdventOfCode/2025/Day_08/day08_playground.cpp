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

class DSU
{
public:
    DSU(int n) : parent(n), sz(n, 1)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int a)
    {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB)
        {
            if (sz[rootA] < sz[rootB])
            {
                parent[rootA] = rootB;
            }
            else if (sz[rootA] > sz[rootB])
            {
                parent[rootB] = rootA;
            }
            else
            {
                parent[rootB] = rootA;
            }

            total = sz[rootA] + sz[rootB];
            sz[rootA] = total;
            sz[rootB] = total;
        }
    }

    void print_sizes()
    {
        for (int i = 0; i < parent.size(); ++i)
        {
            cout << "Element: " << i << ", Parent: " << parent[i] << ", Size: " << sz[i] << endl;
        }
    }

    vector<long long> get_top_3_sizes()
    {
        vector<long long> sizes;
        set<int> unique_parents;
        for (int i = 0; i < parent.size(); ++i)
        {
            int root = find(i);
            if (unique_parents.find(root) == unique_parents.end())
            {
                unique_parents.insert(root);
                sizes.push_back(sz[root]);
            }
        }

        // Descent sort and get top 3
        sort(sizes.begin(), sizes.end(), greater<long long>());

        if (sizes.size() > 3)
            sizes.resize(3);
        return sizes;
    }

private:
    vector<int> parent;
    vector<int> sz;
    int total;
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

long long sq(long long val)
{
    return val * val;
}

long long get_distance(Point3D p1, Point3D p2)
{
    return sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z);
}

bool compare_distance(const array<long long, 3>& a, const array<long long, 3>& b)
{
    return a[0] < b[0];
}

long long solve_part1(const vector<Point3D>& points, const int pairs_to_process)
{
    long long result = 1;
    vector<array<long long, 3> > distances;

    for (int i = 0; i< points.size(); ++i)
    {
        for (int j = i + 1; j < points.size(); ++j)
        {
            long long dist = get_distance(points[i], points[j]);
            distances.push_back({dist, i, j});
        }
    }
    sort(distances.begin(), distances.end(), compare_distance);
    DSU dsu(points.size());
    for (int i = 0; i < pairs_to_process; ++i)
    {
        dsu.unite(distances[i][1], distances[i][2]);
    }

    // dsu.print_sizes();

    cout << "Top 3 sizes: ";
    vector<long long> top_sizes = dsu.get_top_3_sizes();
    for (long long size : top_sizes)
    {
        cout << size << " ";
        result *= size;
    }
    cout << endl;

    return result;
}

long long solve_part2(const vector<Point3D>& points)
{
    long long result = 1;
    vector<array<long long, 3> > distances;

    for (int i = 0; i< points.size(); ++i)
    {
        for (int j = i + 1; j < points.size(); ++j)
        {
            long long dist = get_distance(points[i], points[j]);
            distances.push_back({dist, i, j});
        }
    }
    sort(distances.begin(), distances.end(), compare_distance);
    DSU dsu(points.size());
    for (int i = 0; i < distances.size(); ++i)
    {
        dsu.unite(distances[i][1], distances[i][2]);
    }

    dsu.print_sizes();

    cout << "Top 3 sizes: ";
    vector<long long> top_sizes = dsu.get_top_3_sizes();
    for (long long size : top_sizes)
    {
        cout << size << " ";
        result *= size;
    }
    cout << endl;

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
        // long long part1_result = solve_part1(points, pairs_to_process);
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = solve_part2(points);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}