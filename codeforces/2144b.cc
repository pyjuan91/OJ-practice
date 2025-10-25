#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int xl(int n, vector<int>& a)
{
    int left = 0, right = n - 1;
    while (left <= right && a[left] == left + 1)
        left++;
    while (right >= left && a[right] == right + 1)
        right--;
    return right - left + 1;
}

int patty(int n, vector<int>& a)
{
    vector<bool> used(n + 1, false);
    int zeros = 0;
    for (const auto& x : a)
    {
        used[x] = true;
        if (x == 0)
            zeros++;
    }
    if (zeros <= 1)
    {
        int target = 0;
        for (int i = 1; i <= n; i++)
            if (!used[i])
                target = i;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                a[i] = target;
    }
    return xl(n, a);
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << patty(n, a) << "\n";
    }
    return 0;
}
