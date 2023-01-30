#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int main(void)
{
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    char g[10][10];
    pair<int, int> lake, barn;
    int res;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'B')
                barn = make_pair(i, j);
            if (g[i][j] == 'L')
                lake = make_pair(i, j);
        }

    queue<pair<int, int>> q;
    queue<int> step;
    q.push(lake);
    step.push(0);
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int cur_step = step.front();
        step.pop();
        if (cur == barn) {
            res = cur_step;
            break;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> neo
                = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (neo == barn) {
                cout << cur_step;
                return 0;
            }
            if (neo.first < 0 || neo.first > 9
                || neo.second < 0 || neo.second > 9
                || g[neo.first][neo.second] != '.')
                continue;
            q.push(neo);
            g[neo.first][neo.second] = 'L';
            step.push(cur_step + 1);
        }
    }
    return 0;
}