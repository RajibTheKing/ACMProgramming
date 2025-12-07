int solve_part2(vector<string>& input_lines)
{
     // Implement the logic for part 1 here
    int result = 0;
    int totalRemoved = 0;
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int row = input_lines.size();
    int col = input_lines[0].size();
    bool color[150][150];
    while(true)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                color[i][j] = false;
            }
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (input_lines[i][j] == '@')
                {
                    // check all 8 directions
                    int countAdj = 0;
                    for (int dir = 0; dir < 8; ++dir)
                    {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if (ni >= 0 && ni < row && nj >= 0 && nj < col)
                        {
                            if (input_lines[ni][nj] == '@')
                            {
                                countAdj++;
                            }
                        }
                    }
                    if (countAdj < 4)
                    {
                        color[i][j] = true;
                        result++;
                    }
                }
            }
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (color[i][j])
                {
                    input_lines[i][j] = '.';
                }
            }
        }
        totalRemoved += result;
        if (result == 0)
        {
            break;
        }
        result = 0;
    }

    return totalRemoved;
}