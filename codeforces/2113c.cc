#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int n, int m, int k, vector<string>& a)
{
    vector prefix(n, vector<int>(m, 0));
    int all_golds = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'g')
                prefix[i][j] = 1, all_golds++;
            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];
            if (i > 0 and j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    auto find_sum = [&](int x1, int y1, int x2, int y2) -> int
    {
        x1 = max(x1, 0LL), y1 = max(y1, 0LL);
        x2 = min(x2, n - 1), y2 = min(y2, m - 1);
        int res = prefix[x2][y2] - (x1 == 0 ? 0 : prefix[x1 - 1][y2]) - (y1 == 0 ? 0 : prefix[x2][y1 - 1])
            + ((x1 == 0 || y1 == 0) ? 0 : prefix[x1 - 1][y1 - 1]);
        return all_golds - res;
    };

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
                res = max(res, find_sum(i - k + 1, j - k + 1, i + k - 1, j + k - 1));
        }
    }
    return res;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        vector<string> a(n);
        for (auto& s : a)
            cin >> s;
        cout << patty(n, m, k, a) << "\n";
    }
    return 0;
}
