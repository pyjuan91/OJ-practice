#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(void)
{
    srand(time(nullptr));
    int x =rnad();
    cout << x << endl;
    cout << RAND_MAX << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    map<int, int> m;
    cin >> n;
    while (n--) {
        cin >> x;
        if (!m.count(x))
            m[x] = 1;
        else
            m[x] += 1;
    }
    auto iter = m.end();
    iter--;
    int ma = iter->first;
    vector<vector<int>> prime_factor(ma + 1);

    for (int i = 2; i <= ma; i++) {
        if (prime_factor[i].empty()) {
            for (int j = i; j <= ma; j += i) {
                prime_factor[j].emplace_back(i);
            }
        }
    }

    // for (int i = 2; i <= ma; i++) {
    //     cout << i << ": ";
    //     for (int& j : prime_factor[i])
    //         cout << j << " ";
    //     cout << endl;
    // }

    int cnt = 0;
    for (auto it1 = m.begin(); it1 != m.end(); it1++) {
        for (auto it2 = it1; it2 != m.end(); it2++) {
            if (it2 == it1)
                continue;
            vector<int> check;
            set_intersection(prime_factor[it1->first].begin(),
                prime_factor[it1->first].end(),
                prime_factor[it2->first].begin(),
                prime_factor[it2->first].end(),
                back_inserter(check));
            if (check.empty()) {
                cnt += it1->second * it2->second;
                // cout << it1->first << " " << it1->second << endl;
                // cout << it2->first << " " << it2->second << endl;
            }
        }
    }
    if (m[1] > 1) {
        cnt += m[1] * (m[1] - 1) / 2;
    }
    cout << cnt << endl;

    return 0;
}