#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
using namespace std;
int t, n, a[25], used[25], sum, sel[4], ma;
bool checker;
void input(void);
void init(void);
bool valid(int edge);
bool solve(int edge, int cur, int pos);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        init();
        input();

        if (sum % 4 || ma > sum / 4) {
            cout << "no\n";
            continue;
        }

        if (solve(sum / 4, 0, 0))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
void input(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        ma = max(ma, a[i]);
    }
}
void init(void)
{
    memset(used, 0, sizeof(used));
    memset(sel, 0, sizeof(sel));
    sum = 0;
    checker = false;
    ma = INT_MIN;
}
bool solve(int edge, int cur, int pos)
{
    if (cur == 3)
        return true;

    if (sel[cur] == edge) {
        return solve(edge, cur + 1, 0);
    }

    for (int i = pos; i < n; i++) {
        if (used[i] == 0 && sel[cur] + a[i] <= edge) {
            used[i] = 1;
            sel[cur] += a[i];
            if (solve(edge, cur, i + 1))
                return true;
            used[i] = 0;
            sel[cur] -= a[i];
        }
    }
    return false;
}