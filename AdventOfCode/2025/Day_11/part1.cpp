unordered_map<string, vector<string>> graph;
unordered_map<string, long long> memo;

long long dfs(const string& node)
{
    if (node == "out")
        return 1;

    if (memo.count(node))
        return memo[node];

    long long total = 0;
    for (const string& next : graph[node]) {
        total += dfs(next);
    }

    return memo[node] = total;
}