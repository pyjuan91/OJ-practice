#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
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

bool is_prime(int x)
{
    return lp[x] == x;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << 1 << "\n";
        return 0;
    }

    int cur_sum = 5, res = 1;
    for (int i = 2; i < pr.size(); i++)
    {
        if (cur_sum + pr[i] > n)
            break;
        cur_sum += pr[i];
        if (is_prime(cur_sum))
            res++;
    }
    cout << res << "\n";
    return 0;
}
