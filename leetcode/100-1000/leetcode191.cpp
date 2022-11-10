#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        uint32_t comp;
        for (int i = 0; i < 32; i++) {
            comp = 0;
            comp = n & 1;
            if (comp == 1) {
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}