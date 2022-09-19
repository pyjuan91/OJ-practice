// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// using namespace std;
// int main(void)
// {
//     int t, n, res, ma;
//     unordered_set<int> hasSetZero;
//     unordered_set<int> readyToSetZero;
//     cin >> t;
//     while (t--) {
//         res = ma = 0;
//         hasSetZero.clear();
//         readyToSetZero.clear();
//         cin >> n;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//             cin >> v[i];
//         for (int i = 0; i < n; i++) {
//             if (hasSetZero.find(v[i]) != hasSetZero.end()) {
//                 if (readyToSetZero.empty())
//                     continue;
//                 res += readyToSetZero.size();
//                 for (int entry : readyToSetZero) {
//                     hasSetZero.insert(entry);
//                 }
//                 readyToSetZero.clear();
//             } else {
//                 if (v[i] < ma) {
//                     res += readyToSetZero.size();
//                     for (int entry : readyToSetZero) {
//                         hasSetZero.insert(entry);
//                     }
//                     if (readyToSetZero.find(v[i]) == readyToSetZero.end()) {
//                         ma = v[i];
//                         readyToSetZero.insert(v[i]);
//                     } else
//                         ma = 0;
//                     readyToSetZero.clear();
//                 } else {
//                     ma = v[i];
//                     readyToSetZero.insert(v[i]);
//                 }
//             }
//         }
//         cout << res << "\n";
//     }
//     return 0;
// }

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int N = 1e5 + 5;

int a[N], s[N];
map<int, int> b;
map<int, int> vis;
int main()
{
    int t;
    cin >> t;
    int n;
    while (t--) {
        b.clear();
        vis.clear();
        cin >> n;
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1];
            cin >> a[i];
            b[a[i]] = i;
            vis[a[i]]++;
            if (vis[a[i]] == 1)
                s[i]++;
            // cout<<s[i]<<" ";
        }
        // cout<<endl;
        int cnt = -1;
        for (int i = n; i >= 1; i--) {
            if (a[i - 1] > a[i]) {
                cnt = i - 1;
                break;
            }
        }
        if (cnt == 0 || n == 1 || cnt == -1) {
            printf("0\n");
            continue;
        }
        int ma = -1, ans = 0;
        for (int i = 1; i <= cnt; i++) {
            ma = max(ma, b[a[i]]);
        }
        // cout<<cnt<<" "<<ma<<endl;
        ans = s[ma];
        cout << ans << endl;
    }
    return 0;
}