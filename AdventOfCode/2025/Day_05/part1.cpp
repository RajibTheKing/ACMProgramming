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

long long solve_part1(const vector<string>& ranges, const vector<string>& numbers)
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
    for (const auto& number_str : numbers) {
        long long number = stoll(number_str);
        for (const auto& cafeteria : cafeterias) {
            if (cafeteria.isFresh(number)) {
                result++;
                break;
            }
        }
    }
    return result;
}