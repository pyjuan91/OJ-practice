// #include <bits/stdc++.h>
// using namespace std;
// int main(void)
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v(n + 1);
//     vector<bool> checker(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> v[i];
//     }
//     while (m--) {
//         fill(checker.begin(), checker.end(), false);
//         for (int i = 1; i <= n; i++) {
//             v[i] += i;
//             if (v[i] >= 0 && v[i] <= n) {
//                 checker[v[i]] = true;
//             }
//         }
//         for (int i = 0; i <= n; i++) {
//             if (checker[i] == false) {
//                 cout << i << "\n";
//                 break;
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& v : a)
        cin >> v;
    vector<vector<int>> vals(m + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] >= n)
            continue;
        int l = (a[i] >= 0 ? 1 : (-a[i] + i) / (i + 1));
        int r = min(m + 1, (n - a[i] + i) / (i + 1));
        for (int j = l; j < r; j++) {
            vals[j].push_back(a[i] + (i + 1) * j);
        }
    }
    for (int i = 1; i <= m; i++) {
        int sz = vals[i].size();
        vector<bool> exi(sz + 1);
        for (auto v : vals[i]) {
            if (v < sz)
                exi[v] = true;
        }
        int res = 0;
        while (exi[res])
            res++;
        cout << res << endl;
    }
}
