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
            int rotation = std::stoi(line.substr(1));
            int fullRotations = floor(rotation / 100);
            cnt += fullRotations;
            int remainingRotation = rotation % 100;
            if (seq != 0 && seq - remainingRotation <= 0)
            {
                cnt += 1;
            }
            seq = (seq - remainingRotation + 100) % 100;

        }
        else  // 'R'
        {
            int rotation = std::stoi(line.substr(1));
            int fullRotations = floor(rotation / 100);
            cnt += fullRotations;
            int remainingRotation = rotation % 100;
            if (seq != 0 && seq + remainingRotation >= 100)
            {
                cnt += 1;
            }
            seq = (seq + remainingRotation) % 100;
        }
        // std::cout << "Executed: " << line << " Current seq: " << seq << ", cnt: " << cnt << std::endl;
    }
    input.close();
    return cnt;
}