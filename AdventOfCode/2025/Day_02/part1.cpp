long long solve_part1(const vector<string>& input_lines)
{
    vector<string> ranges;
    long long result = 0;
    for (const auto& line : input_lines)
    {
        // Split the line by comma
        stringstream ss(line);
        string item;
        while (getline(ss, item, ','))
        {
            ranges.push_back(item);
        }
    }

    for (const auto& range : ranges)
    {
        stringstream ss(range);
        string start_str, end_str;
        getline(ss, start_str, '-');
        getline(ss, end_str, '-');
        long long start = stoll(start_str);
        long long end = stoll(end_str);

        for (long long i = start; i <= end; ++i)
        {
            string num_gets = to_string(i);
            for (int j = 0; j < num_gets.size(); ++j)
            {
                string firstPart = num_gets.substr(0, j);
                string secondPart = num_gets.substr(j);
                if(firstPart == secondPart)
                {
                    result+= i;
                }
            }
        }
    }
    return result;
}