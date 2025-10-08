#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e5 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

int init = []() {
    for (int i = 2; i <= kMax; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= kMax; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
            {
                break;
            }
        }
    }
    return 0;
}();

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int l, r;
    cin >> l >> r;
    unordered_set<int> np;
    if (l == 1)
    {
        np.insert(1);
    }
    for (const auto& p : pr)
    {
        for (int j = max(2LL, (l + p - 1) / p); j * p <= r; ++j)
        {
            np.insert(j * p);
        }
    }
    cout << r - l + 1 - np.size() << "\n";
    return 0;
}
