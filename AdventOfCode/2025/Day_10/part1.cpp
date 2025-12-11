#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int solve_part1( int target_light_state, const vector<int>& button, const vector<int>& joltage_requirement)
{
    map<int, int> dist;
    queue<pair<int, int>> q; // {state, buttons_pressed}

    q.push({0, 0});
    dist[0] = 0;

    while(!q.empty())
    {
        int state = q.front().first;
        int buttons_pressed = q.front().second;
        q.pop();

        if (state == target_light_state)
        {
            return buttons_pressed;
        }

        for (int i = 0; i < button.size(); ++i)
        {
            int newState = state ^ button[i];
            if (dist.find(newState) == dist.end())
            {
                dist[newState] = buttons_pressed + 1;
                q.push({newState, buttons_pressed + 1});
            }
        }
    }
    return INT_MAX; // No solution found
}

int main()
{
    ifstream input("input.txt");
    string line;
    getline(input, line);
    int testCases = stoi(line);
    long long sum = 0;

    for (int kase = 1; kase <= testCases; ++kase)
    {
        sum = 0;

        while(getline(input, line) && !line.empty())
        {
            int target_light_state = 0;
            vector<int> button;
            vector<int> joltage_requirement;

            vector<string> tokens = split(line, ' ');
            string light_state = tokens[0];

            // remove first '[' and last ']' from light_state
            light_state = light_state.substr(1, light_state.size() - 2);
            for (int i = 0; i < light_state.size(); ++i)
            {
                if (light_state[i] == '#')
                {
                    target_light_state |= (1 << i);
                }
            }
            for (int j = 1; j < tokens.size() - 1; ++j)
            {
                // remove first '(' and last ')' from button token
                string button_token = tokens[j];
                button_token = button_token.substr(1, button_token.size() - 2);
                vector<string> button_nums = split(button_token, ',');
                int button_group = 0;
                for (const string& num_str : button_nums)
                {
                    int btn = stoi(num_str);
                    button_group |= (1 << btn);
                }
                button.push_back(button_group);
            }

            string joltage_str = tokens.back();
            // remove first '{' and last '}' from joltage_str
            joltage_str = joltage_str.substr(1, joltage_str.size() - 2);
            vector<string> joltage_nums = split(joltage_str, ',');
            for (const string& num_str : joltage_nums)
            {
                joltage_requirement.push_back(stoi(num_str));
            }

            long long cur = solve_part2(target_light_state, button, joltage_requirement);
            sum += cur;
        }

        long long part1_result = sum;
        cout << "Part 1 result for test case #" << kase << ": " << part1_result << endl;
    }
}