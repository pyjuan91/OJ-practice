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
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        vector<int> pre_xor(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pre_xor[i] = pre_xor[i - 1] ^ a[i - 1];
        }

        int tot_cost = 0;
        map<int, pair<int, int>> xor_map; // xor_value -> {count, total_index_sum}
        xor_map[0] = { 1, 0 };

        int tot_count = 1;
        int tot_index_sum = 0;

        for (int i = 1; i <= n; i++)
        {
            int cur_xor = pre_xor[i];
            int tot_len_sum = tot_count * i - tot_index_sum;

            if (xor_map.count(cur_xor))
            {
                auto [count, index_sum] = xor_map[cur_xor];
                int same_len_sum = count * i - index_sum;
                tot_cost += tot_len_sum - same_len_sum;

                int same_contrib = count * i - index_sum - count * (count + 1) / 2;
                tot_cost += same_contrib;
            }
            else
            {
                tot_cost += tot_len_sum;
            }

            xor_map[cur_xor].first += 1;
            xor_map[cur_xor].second += i;
            tot_count += 1;
            tot_index_sum += i;
        }

        cout << "Case #" << kase << ": " << tot_cost << "\n";
    }
    return 0;
}
