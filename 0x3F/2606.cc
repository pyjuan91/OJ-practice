#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals)
    {
        array<int, 26> cost;
        for (char c = 'a'; c <= 'z'; c++)
            cost[c - 'a'] = (c - 'a' + 1);
        for (size_t i = 0; i < chars.size(); i++)
            cost[chars[i] - 'a'] = vals[i];

        int max_cost_all_time = 0, max_cost_so_far = 0;
        for (const auto& c : s) {
            max_cost_so_far = max(0, max_cost_so_far + cost[c - 'a']);
            max_cost_all_time = max(max_cost_all_time, max_cost_so_far);
        }
        return max_cost_all_time;
    }
};

int main()
{
    return 0;
}