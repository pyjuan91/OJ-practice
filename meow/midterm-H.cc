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
bool solve(int done, int now, int last)
{
    if (done == target)
        return true;
    if (now == len)
        return solve(done + 1, 0, 1);
    int fail = -1;
    for (int i = last; i <= n; i++) {
        if (used[i] || now + a[i] > len || a[i] == fail)
            continue;
        used[i] = true;
        if (solve(done, now + a[i], i + 1))
            return true;
        used[i] = 0;
        a[i] = fail;
        if(now == 0 || now + a[i] == len)return false;
    }
    return false;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n && n) {
        int res = 0, ma = INT_MIN, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        ma = a[0];
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