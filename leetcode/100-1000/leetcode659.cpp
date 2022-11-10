#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int, int> cnt, tails;
        for (auto i : nums) {
            cnt[i]++;
        }
        for (auto i : nums) {
            if (!cnt[i])
                continue;
            cnt[i]--;
            if (tails[i - 1] > 0) {
                tails[i - 1] -= 1;
                tails[i] += 1;
            } else {
                if (!cnt[i + 1] || !cnt[i + 2])
                    return false;
                cnt[i + 1] -= 1, cnt[i + 2] -= 1;
                tails[i + 2] += 1;
            }
        }
        return true;
    }
};
int main(void) { return 0; }