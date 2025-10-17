#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;

int op(int a, int b)
{
    return max(a, b);
}

int e()
{
    return 0;
}

constexpr int kMax = 100005;
atcoder::segtree<int, op, e> seg(kMax);

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        size_t n = nums.size();
        for (auto& num : nums)
        {
            num += 10001;
            seg.set(num, seg.prod(1, num) + 1);
        }
        return seg.all_prod();
    }
};

int main() { return 0; }