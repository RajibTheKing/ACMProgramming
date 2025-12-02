#include <iostream>
#include <fstream>

int main() 
{
    std::ifstream input("day01_secret_password_input.txt");
    std::string line;
    int seq = 50;
    int cnt = 0;
    while (std::getline(input, line))
    {
        if (line[0] == 'L')
        {
            int rotate = std::stoi(line.substr(1));
            seq -= rotate;
        }
        else
        {
            int rotate = std::stoi(line.substr(1));
            seq += rotate;
        }

        seq = (seq % 100 + 100) % 100;

        if (seq == 0)
        {
            cnt++;
        }
    }
    
    std::cout << cnt << std::endl;
    input.close();
    
    return 0;
}