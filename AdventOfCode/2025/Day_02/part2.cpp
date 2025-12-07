bool isRepeatableByStep(int step, const string& num_gets)
{
    if (num_gets.size() % step != 0)
    {
        return false;
    }

    for (size_t i = 0; i < num_gets.size(); i += step)
    {
        string segment = num_gets.substr(i, step);
        for (size_t j = i + step; j < num_gets.size(); j += step)
        {
            string nextSegment = num_gets.substr(j, step);
            if (segment != nextSegment)
            {
                return false;
            }
        }
    }
    return true;
}

bool isInvalid(string num_gets)
{
    // check if all digitst are the same
    for (int i = 1; i < num_gets.size(); ++i)
    {
        if (isRepeatableByStep(i, num_gets))
        {
            return true;
        }
    }
    return false;
}

long long solve_part2(const vector<string>& input_lines)
{
    vector<string> ranges;
    long long result = 0;
    for (const auto& line : input_lines)
    {
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
            if(isInvalid(num_gets))
            {
                result+=i;
            }
        }
    }

    return result;
}
