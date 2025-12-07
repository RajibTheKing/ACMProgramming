int solve()
{
    std::ifstream input("input.txt");
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

        seq = seq % 100;

        if (seq == 0)
        {
            cnt++;
        }
    }

    input.close();
    return cnt;
}

