long long dp[160][160];

long long solve_part2(int row, int col, vector<string>& input_lines)
{
    // cout << "At position (" << row << ", " << col << ")\n";

    if (row >= input_lines.size() - 1 || col < 0 || col >= input_lines[row].size())
        return 1;

    if (input_lines[row + 1][col] == '.')
        return 1;

    long long &ret = dp[row][col];
    if (ret != -1) return ret;
    ret = 0;

    if (input_lines[row + 1][col] == '|')
    {
        ret += solve_part2(row + 1, col, input_lines);
    }
    else if (input_lines[row + 1][col] == '^')
    {
        // When we hit a ^, we branch to both left and right
        ret += solve_part2(row + 1, col - 1, input_lines);
        ret += solve_part2(row + 1, col + 1, input_lines);
    }
    else if (input_lines[row + 1][col] == 'S')
    {
        // Treat 'S' as continuation down
        ret += solve_part2(row + 1, col, input_lines);
    }
    return ret;
}
