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