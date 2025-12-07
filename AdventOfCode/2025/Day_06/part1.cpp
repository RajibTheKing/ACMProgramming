long long solve_part1(const vector<string>& input_lines)
{
    long long result = 0;
    vector<vector<long long>> numbers;
    numbers.clear();
    for (int i = 0; i < input_lines.size() - 1; ++i)
    {
        const string& line = input_lines[i];

        istringstream iss(line);
        vector<long long> row;
        long long num;
        while (iss >> num)
        {
            row.push_back(num);
        }
        numbers.push_back(row);

    }
    vector<char> operators;
    const string& ops_line = input_lines.back();
    istringstream ops_iss(ops_line);
    char op;
    while (ops_iss >> op)
    {
        operators.push_back(op);
    }

    for (int j = 0; j < operators.size(); ++j)
    {
        char current_op = operators[j];
        long long current_result = numbers[0][j];
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (current_op == '+')
            {
                current_result += numbers[i][j];
            }
            else if (current_op == '*')
            {
                current_result *= numbers[i][j];
            }
        }
        result += current_result;
    }
    return result;
}
