#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int sum = 0, pos = 1;
        sort(nums.begin(), nums.end());
        for(auto i:nums)
        {
            sum += pos * i;
            pos *= -1;
        }
        return sum;
    }
};
int main(void)
{
    return 0;
}