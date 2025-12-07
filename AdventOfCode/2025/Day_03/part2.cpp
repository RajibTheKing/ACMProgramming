int solve_part2()
{
    ifstream input("input.txt");
    string line;
    long long totalJoltage = 0;

    while (getline(input, line))
    {
        const int numberOfDigits = 12;
        char maxDigits[numberOfDigits];
        int maxIndices[numberOfDigits];

        for (int d = 0; d < numberOfDigits; d++)
        {
            maxDigits[d] = '0' - 1; // Initialize to a value less than any digit
            maxIndices[d] = -1;
        }

        for (int d = 0; d < numberOfDigits; d++)
        {
            int startPos = (d > 0) ? maxIndices[d-1] + 1 : 0;
            int endPos = line.size() - numberOfDigits + d;

            for (int i = startPos; i <= endPos; i++)
            {
                if (line[i] > maxDigits[d])
                {
                    maxDigits[d] = line[i];
                    maxIndices[d] = i;
                }
            }
        }

        long long maxJoltage = maxDigits[0] - '0';
        for (int d = 1; d < numberOfDigits; d++)
        {
            maxJoltage = (long long) maxJoltage * 10 + (maxDigits[d] - '0');
        }

        totalJoltage += maxJoltage;

    }
    input.close();
    return totalJoltage;
}