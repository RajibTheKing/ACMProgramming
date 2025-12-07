long long solve_part1(vector<string>& input_lines)
{
    // Implement the logic for part 1 here
    long long result = 0;
    for (int i = 1; i < input_lines.size(); ++i)
    {
        for (int j = 0; j < input_lines[i].size(); ++j)
        {
            // Example processing logic
            if (input_lines[i-1][j] == 'S')
            {
                input_lines[i][j] = '|';
            }

            if (input_lines[i][j] == '^' && input_lines[i-1][j] == '|')
            {
                result += 1;
                input_lines[i][j-1] = '|';
                input_lines[i][j+1] = '|';
            }

            if (input_lines[i][j] == '.' && input_lines[i-1][j] == '|')
            {
                input_lines[i][j] = '|';
            }
        }
    }
    return result;
}
