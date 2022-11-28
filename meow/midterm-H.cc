#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
vector<bool> used(70);
vector<int> a(70);
int n;
int target;
int len;
bool solve(int finish_sticks, int now_len, int last)
{
    if (finish_sticks >= target)
        return true;
    if (now_len == len)
        return solve(finish_sticks + 1, 0, 1);
    for (int i = last; i <= n; i++) {
        if (used[i] || now_len + a[i] > len)
            continue;
        used[i] = true;
        if (solve(finish_sticks, now_len + a[i], i + 1))
            return true;
        used[i] = 0;
        if (now_len == 0|| now_len + a[i] == len)
            return false;
    }
    return false;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n && n) {
        int ma = INT_MIN, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin() + 1, a.begin() + 1 + n, greater<int>());
        ma = a[1];
        for (int i = ma; i <= sum; i++) {
            if (sum % i == 0) {
                target = sum / i;
                len = i;
                fill(used.begin(), used.end(), false);
                if (solve(0, 0, 1)) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}