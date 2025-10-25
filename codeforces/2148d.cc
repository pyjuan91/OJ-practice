#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> nums(2);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums[x % 2].push_back(x);
        }
        if (nums[1].empty())
        {
            cout << "0\n";
            continue;
        }
        int res = accumulate(nums[0].begin(), nums[0].end(), 0LL);
        sort(nums[1].rbegin(), nums[1].rend());
        for (int i = 0; i < nums[1].size() / 2; i++)
            res += nums[1][i];
        if (nums[1].size() % 2)
            res += nums[1][nums[1].size() / 2];
        cout << res << "\n";
    }
    return 0;
}
