#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    // std::ifstream input("day03_Lobby_input_easy.txt");
    ifstream input("day03_Lobby_input_hard.txt");
    string line;
    long long totalJoltage = 0;

    while (getline(input, line))
    {
        cout << "Processing line: " << line << endl;
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

        cout << "maxjoltage: " << maxJoltage << endl;
        totalJoltage += maxJoltage;

    }
    cout << totalJoltage << endl;
    input.close();
    return 0;
}