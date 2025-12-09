#include <bits/stdc++.h>
using namespace std;

class Cord
{
public:
    Cord( int a,  int b ) : x(a), y(b) {}

    bool operator<(const Cord& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    int x;
    int y;
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

unordered_map<int, int> max_row_in_column;
unordered_map<int, int> min_row_in_column;
unordered_map<int, int> max_col_in_row;
unordered_map<int, int> min_col_in_row;

void updateBoundary(int x, int y)
{
    if (max_row_in_column.find(y) == max_row_in_column.end() || x > max_row_in_column[y])
    {
        max_row_in_column[y] = x;
    }
    if (min_row_in_column.find(y) == min_row_in_column.end() || x < min_row_in_column[y])
    {
        min_row_in_column[y] = x;
    }
    if (max_col_in_row.find(x) == max_col_in_row.end() || y > max_col_in_row[x])
    {
        max_col_in_row[x] = y;
    }
    if (min_col_in_row.find(x) == min_col_in_row.end() || y < min_col_in_row[x])
    {
        min_col_in_row[x] = y;
    }
}

bool isInsideBoundary(int x, int y)
{
    if (max_row_in_column.find(y) != max_row_in_column.end() &&
        min_row_in_column.find(y) != min_row_in_column.end() &&
        max_col_in_row.find(x) != max_col_in_row.end() &&
        min_col_in_row.find(x) != min_col_in_row.end())
    {
        return (x >= min_row_in_column[y] && x <= max_row_in_column[y] &&
                y >= min_col_in_row[x] && y <= max_col_in_row[x]);
    }
    return false;
}

long long solve_part2(vector<Cord>& cords)
{
    long long result = 0;

     max_row_in_column.clear();
     min_row_in_column.clear();
     max_col_in_row.clear();
     min_col_in_row.clear();

    for (const auto& cord : cords)
    {
        updateBoundary(cord.x, cord.y);
    }

    // scan over the columns
    for (const auto& cord : cords)
    {
        int x = cord.x;
        int y = cord.y;
        int max_row = max_row_in_column[y];
        int min_row = min_row_in_column[y];
        int max_col = max_col_in_row[x];
        int min_col = min_col_in_row[x];
        for (int i = min_row; i <= max_row; ++i)
        {
            updateBoundary(i, y);
        }
        for (int j = min_col; j <= max_col; ++j)
        {
            updateBoundary(x, j);
        }
    }

    for (int i = 0; i < cords.size(); ++i)
    {
        for (int j = i + 1; j < cords.size(); ++j)
        {
            long long side1 = (max(cords[i].x , cords[j].x) - min(cords[i].x , cords[j].x)) + 1;
            long long side2 = (max(cords[i].y , cords[j].y) - min(cords[i].y , cords[j].y)) + 1;

            // calculate other two corners
            int x1 = cords[i].x;
            int y1 = cords[j].y;
            int x2 = cords[j].x;
            int y2 = cords[i].y;
            if (isInsideBoundary(x1, y1) && isInsideBoundary(x2, y2))
            {
                long long area = side1 * side2;
                if (area > result)
                {
                    result = area;
                }
            }
        }
    }

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
        // long long part1_result = solve_part1(cords);
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = solve_part2(cords);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}