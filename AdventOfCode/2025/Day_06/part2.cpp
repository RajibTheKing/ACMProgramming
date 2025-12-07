long long solve_part2(const vector<string>& input_lines)
{
    long long result = 0;
    vector<char> operators;
    const string& ops_line = input_lines.back();
    istringstream ops_iss(ops_line);
    char op;
    while (ops_iss >> op)
    {
        operators.push_back(op);
    }

    int current_col_index = 0;
    for (int j = 0; j < operators.size(); ++j)
    {
        char current_op = operators[j];
        long long current_result = -1;
        while (current_col_index < input_lines[0].size())
        {
            long long currentNumber = 0;
            for (int i = 0; i < input_lines.size() - 1; ++i)
            {
                if (input_lines[i][current_col_index] != ' ')
                {
                    currentNumber = currentNumber * 10 + input_lines[i][current_col_index] - '0';
                }
            }
            current_col_index++;
            if (currentNumber == 0)
            {
                break;
            }

            if (current_result == -1)
            {
                current_result = currentNumber;
            }
            else
            {
                if (current_op == '+')
                {
                    current_result += currentNumber;
                }
                else if (current_op == '*')
                {
                    current_result *= currentNumber;
                }
            }
        }
        result += current_result;
    }
    return result;
}