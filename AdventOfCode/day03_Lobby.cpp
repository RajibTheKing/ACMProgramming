#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    // std::ifstream input("day03_Lobby_input_easy.txt");
    std::ifstream input("day03_Lobby_input_hard.txt");
    std::string line;
    int totalJoltage = 0;

    while (std::getline(input, line))
    {
        std::cout << "Processing line: " << line << std::endl;
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
        std::cout << "Max left: " << maxLeft << " at index " << maxLeftIndex << ", Max right: " << maxRight << " at index " << maxRightIndex << ", Max joltage: " << maxJoltage << std::endl;
        totalJoltage += maxJoltage;

    }
    std::cout << totalJoltage << std::endl;
    input.close();
    return 0;
}