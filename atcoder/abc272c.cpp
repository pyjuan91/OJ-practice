#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, odd1 = -1, odd2 = -1, even1 = -1, even2 = -1, p1 = -1, p2 = -1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    auto iter = unique(v.begin(), v.end());
    n = iter - v.begin();
    for (int i = n - 1; i >= 0; i--) {
        if (odd2 != -1 && even2 != -1)
            break;
        if (odd2 == -1 && v[i] % 2 == 1) {
            if (odd1 == -1) {
                odd1 = v[i];
            } else {
                odd2 = v[i];
            }
        } else if (even2 == -1 && v[i] % 2 == 0) {
            if (even1 == -1) {
                even1 = v[i];
            } else {
                even2 = v[i];
            }
        }
    }
    if (odd2 != -1) {
        p1 = odd1 + odd2;
    }
    if (even2 != -1) {
        p2 = even1 + even2;
    }

    if (p1 != -1 && p2 != -1) {
        cout << max(p1, p2) << "\n";
    } else if (p1 != -1) {
        cout << p1 << "\n";
    } else if (p2 != -1) {
        cout << p2 << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}