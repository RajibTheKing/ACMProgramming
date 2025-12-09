long long solve_part1(vector<Cord>& cords)
{
    long long result = 0;
    sort(cords.begin(), cords.end(), [](const Cord& a, const Cord& b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    for (int i = 0; i < cords.size(); ++i)
    {
        for (int j = i + 1; j < cords.size(); ++j)
        {
            long long side1 = (max(cords[i].x , cords[j].x) - min(cords[i].x , cords[j].x)) + 1;
            long long side2 = (max(cords[i].y , cords[j].y) - min(cords[i].y , cords[j].y)) + 1;
            long long area = side1 * side2;
            // cout << "Calculating area between points (" << cords[i].x << "," << cords[i].y << ") and (" << cords[j].x << "," << cords[j].y << ")" << " Area = " << area << endl;
            if (area > result)
            {
                result = area;
            }
        }
    }

    return result;
}