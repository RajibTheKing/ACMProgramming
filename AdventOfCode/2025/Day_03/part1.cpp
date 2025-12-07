int solve_part1()
{
    std::ifstream input("input.txt");
    std::string line;
    int totalJoltage = 0;

    while (std::getline(input, line))
    {
        char maxLeft = line[line.size() - 2];
        char maxRight = line[line.size() - 1];
        int maxLeftIndex = line.size() - 2;
        int maxRightIndex = line.size() - 1;

        for (int i = line.size() - 2; i>=0; i--)
        {
            if (line[i] >= maxLeft)
            {
                maxLeft = line[i];
                maxLeftIndex = i;
            }
        }

        for (int i = line.size() - 1; i>maxLeftIndex; i--)
        {
            if (line[i] > maxRight)
            {
                maxRight = line[i];
                maxRightIndex = i;
            }
        }

        int maxJoltage = (maxLeft - '0') * 10 + (maxRight - '0');
        totalJoltage += maxJoltage;
    }

    return totalJoltage;
}