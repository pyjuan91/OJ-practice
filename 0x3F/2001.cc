#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles)
    {
        long long res = 0;
        map<pair<int, int>, int> cnt;
        for(const auto& rectangle : rectangles)
        {
            int width = rectangle[0], height = rectangle[1];
            int g = gcd(width, height);
            width /= g, height /= g;
            res += cnt[make_pair(width, height)];
            cnt[make_pair(width, height)]++;
        }
        return res;
    }
};

int main() { return 0; }