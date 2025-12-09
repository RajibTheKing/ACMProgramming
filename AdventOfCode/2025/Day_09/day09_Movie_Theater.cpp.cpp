#include <bits/stdc++.h>
using namespace std;

class Cord
{
public:
    Cord( long long a, long long b ) : x(a), y(b) {}
    long long x;
    long long y;
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

long long solve_part1(vector<Cord>& cords)
{
    long long result = 0;
    sort(cords.begin(), cords.end(), [](const Cord& a, const Cord& b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    for (int i = 0; i < cords.size(); ++i)
    {
        for (int j = i + 1; j < cords.size(); ++j)
        {
            long long side1 = (max(cords[i].x , cords[j].x) - min(cords[i].x , cords[j].x)) + 1;
            long long side2 = (max(cords[i].y , cords[j].y) - min(cords[i].y , cords[j].y)) + 1;
            long long area = side1 * side2;
            // cout << "Calculating area between points (" << cords[i].x << "," << cords[i].y << ") and (" << cords[j].x << "," << cords[j].y << ")" << " Area = " << area << endl;
            if (area > result)
            {
                result = area;
            }
        }
    }

    return result;
}

long long solve_part2(vector<Cord>& cords)
{
    long long result = 0;
    // ...
    return result;
}

int main()
{
    ifstream input("input.txt");
    string line;
    long long column, row;
    getline(input, line);
    int testCases = stoi(line);
    vector<Cord> cords;

    for (int kase = 1; kase <= testCases; ++kase)
    {
        cords.clear();
        vector<string> input_lines;
        // input line is as : 11,78

        while(getline(input, line) && !line.empty())
        {
            input_lines.push_back(line);
            stringstream ss(line);
            char comma;
            ss >> column >> comma >> row;
            cords.emplace_back(column, row);
        }
        long long part1_result = solve_part1(cords);
        cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        // long long part2_result = solve_part2(input_lines);
        // cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}