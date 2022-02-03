#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++)
        {
            auto iter = find(numbers.begin() + i + 1, numbers.end(), target - i);
            if (iter != numbers.end())
            {
                ans.push_back(i + 1);
                ans.push_back(iter - numbers.begin() + 1);
                break;
            }
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}