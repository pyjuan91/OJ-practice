#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumSum(vector<int>& nums)
    {
        unordered_map<int, int> m;
        int res = -1;
        for(const auto& num : nums)
        {
            int digit_sum = 0, x = num;
            while(x)
            {
                digit_sum += x % 10;
                x /= 10;
            }
            if(m.count(digit_sum))
            {
                res = max(res, num + m[digit_sum]);
            }
            m[digit_sum] = max(m[digit_sum], num);
        }
        return res;
    }
};

int main() { return 0; }