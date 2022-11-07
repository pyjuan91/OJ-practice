#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define ff first
#define ss second
using namespace std;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int stp;
bool check(vector<vector<int>>& h, int& n, int diff,
    vector<vector<bool>>& rec)
{
    queue<pair<int, int>> q;
    queue<int> step;

    q.push({ 1, 1 });
    step.push(0);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int cs = step.front();
        q.pop();
        step.pop();

        if(cur.ff == n && cur.ss == n){
            stp = cs;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            pair<int, int> np = make_pair(cur.ff + dx[i], cur.ss + dy[i]);
            if (np.ff < 1 || np.ff > n || np.ss < 1 || np.ss > n
                || rec[np.ff][np.ss] || abs(h[cur.ff][cur.ss] - h[np.ff][np.ss]) > diff)
                continue;

            rec[np.ff][np.ss] = true;
            q.push(np);
            step.push(cs + 1);
        }
    }
    return false;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> h(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> h[i][j];
    }

    int left = 0, right = 1000000, ans;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        vector<vector<bool>> rec(n + 1, vector<bool>(n + 1));
        rec[1][1] = true;
        stp = 0;
        if (check(h, n, mid, rec)) {
            right = mid;
            ans = stp;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
    cout << ans << endl;
    return 0;
}