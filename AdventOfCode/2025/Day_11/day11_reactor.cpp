#include <bits/stdc++.h>
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

// unordered_map<string, vector<string>> graph;
// unordered_map<string, long long> memo;

// long long dfs(const string& node)
// {
//     if (node == "out")
//         return 1;

//     if (memo.count(node))
//         return memo[node];

//     long long total = 0;
//     for (const string& next : graph[node]) {
//         total += dfs(next);
//     }

//     return memo[node] = total;
// }

unordered_map<string, vector<string>> graph;
map<tuple<string, bool, bool>, long long> memo;

long long dfs_part2(const string& node, bool visitedDAC, bool visitedFFT) {
    if (node == "dac") visitedDAC = true;
    if (node == "fft") visitedFFT = true;

    if (node == "out") {
        return (visitedDAC && visitedFFT) ? 1 : 0;
    }

    auto key = make_tuple(node, visitedDAC, visitedFFT);
    if (memo.count(key)) return memo[key];

    long long total = 0;
    for (const string& nxt : graph[node]) {
        total += dfs_part2(nxt, visitedDAC, visitedFFT);
    }

    return memo[key] = total;
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
        graph.clear();
        memo.clear();
        while(getline(input, line) && !line.empty())
        {
            vector<string> parts = split(line, ' ');
            string device = parts[0].substr(0, parts[0].size() - 1); // remove the colon
            for (int i = 1; i < parts.size(); ++i)
            {
                graph[device].push_back(parts[i]);
            }
        }
        // long long part1_result = dfs("you");
        // cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
        long long part2_result = dfs_part2("svr", false, false);
        cout << "Part 2 result for test case #" << kase << ": " << part2_result << endl;
    }
}