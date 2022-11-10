#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (uint32_t i = 0; i <= n; i++) {
            uint32_t x = i;
            int cnt = 0;
            while (x) {
                if (x & 1 == 1)
                    cnt++;
                x >>= 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}