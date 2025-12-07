class Cafeteria
{
public:
    long long left, right;
    Cafeteria(long long left, long long right) : left(left), right(right) {}
    ~Cafeteria() {}
    bool isFresh(long long value) const {
        return value >= left && value <= right;
    }
};

bool CompareCafeteria(const Cafeteria& a, const Cafeteria& b)
{
    return a.left < b.left;
}

long long solve_part2(const vector<string>& ranges)
{
    // Implement the logic for part 1 here
    long long result = 0;
    vector<Cafeteria> cafeterias;

    for (const auto& range_str : ranges) {
        stringstream ss(range_str);
        long long left, right;
        char dash;
        ss >> left >> dash >> right;
        Cafeteria cafeteria(left, right);
        cafeterias.push_back(cafeteria);
    }

    sort(cafeterias.begin(), cafeterias.end(), CompareCafeteria);

    // Merge overlapping ranges
    vector<Cafeteria> merged;
    long long current_left = cafeterias[0].left;
    long long current_right = cafeterias[0].right;
    for (size_t i = 1; i < cafeterias.size(); ++i) {
        if (cafeterias[i].left <= current_right) {
            current_right = max(current_right, cafeterias[i].right);
        } else {
            merged.emplace_back(current_left, current_right);
            current_left = cafeterias[i].left;
            current_right = cafeterias[i].right;
        }
    }
    merged.emplace_back(current_left, current_right);

    // count total fresh numbers
    for (const auto& cafeteria : merged) {
        result += (cafeteria.right - cafeteria.left + 1);
    }
    return result;
}