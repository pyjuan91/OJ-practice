#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int n, string s)
{
    vector<int> pref_zero(n + 2, 0), suff_zero(n + 2, 0);
    vector<int> pref_one(n + 2, 0), suff_one(n + 2, 0);
    s = " " + s + " ";
    for (int i = 1; i <= n; i++)
    {
        pref_zero[i] = pref_zero[i - 1] + (s[i] == '0');
        pref_one[i] = pref_one[i - 1] + (s[i] == '1');
    }
    for (int i = n; i >= 1; i--)
    {
        suff_zero[i] = suff_zero[i + 1] + (s[i] == '0');
        suff_one[i] = suff_one[i + 1] + (s[i] == '1');
    }
    int res = numeric_limits<int>::max();
    int left = 1, right = 1;
    while (right <= n)
    {
        while (right <= n && s[right] == s[left])
            right++;
        if (s[left] == '0')
        {
            int cur_res = 2 * (pref_zero[left - 1] + suff_zero[right]) + (pref_one[left - 1] + suff_one[right]);
            res = min(res, cur_res);
        }
        else
        {
            int cur_res = 2 * (pref_one[left - 1] + suff_one[right]) + (pref_zero[left - 1] + suff_zero[right]);
            res = min(res, cur_res);
        }
        left = right;
    }
    return res;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        cout << patty(n, s) << "\n";
    }
    return 0;
}
