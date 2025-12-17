#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxSum(vector<int>& nums)
    {
        int res = -1;
        vector<int> records(10);

        for(const auto& num : nums)
        {
            int max_digit = 0, x = num;
            while(x)
            {
                max_digit = max(max_digit, x % 10);
                x /= 10;
            }
            if(records[max_digit])
            {
                res = max(res, records[max_digit] + num);
            }
            records[max_digit] = max(records[max_digit], num);
        }

        return res;
    }
};

int main() { return 0; }