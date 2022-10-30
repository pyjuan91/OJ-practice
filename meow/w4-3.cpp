#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& a, int n, int k, long long mid)
{
    long long cur_sum = 0;
    for (int i = 0; i < n; i++) {

        if (a[i] > mid)
            return false;
        if (cur_sum + (long long)a[i] <= mid) {
            cur_sum += a[i];
        } else {
            cur_sum = a[i];
            k--;
        }
        if (k <= 0)
            return false;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, ma = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    long long left = 1, right = (long long)ma * (long long)(n - k + 1);

    while (left + 1 < right) {
        long long mid = left + (right - left) / 2;
        // check
        if (check(a, n, k, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << "\n";

    return 0;
}