#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };
const char dir[4] = { 'R', 'L', 'D', 'U' };
char grid[1005][1005];
int direction[1005][1005];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    pair<int, int> start, end;
    // input
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = { i, j };
            if (grid[i][j] == 'B')
                end = { i, j };
        }

    for (int i = 0; i <= n + 1; i++)
        grid[i][0] = grid[i][m + 1] = '#';
    for (int j = 0; j <= m + 1; j++)
        grid[0][j] = grid[n + 1][j] = '#';

    grid[start.first][start.second] = '#';
    queue<pair<int, int>> point;
    queue<int> step;
    // queue<string> route;

    point.push(start);
    step.push(0);
    // route.push("");

    while (!point.empty()) {
        pair<int, int> cur_point = point.front();
        int cur_step = step.front();
        // string cur_route = route.front();

        point.pop();
        step.pop();
        // route.pop();

        if (cur_point == end) {
            cout << "YES\n"
                 << cur_step << "\n";
            //  << cur_route << "\n";
            vector<char> res;
            while (cur_point != start) {
                res.push_back(dir[direction[cur_point.first][cur_point.second]]);
                cur_point = { cur_point.first - dx[direction[cur_point.first][cur_point.second]],
                    cur_point.second - dy[direction[cur_point.first][cur_point.second]] };
            }
            for (auto i = res.rbegin(); i != res.rend(); i++) {
                cout << *i;
            }
            cout << "\n";
            return 0;
        }

        // if (grid[cur_point.first][cur_point.second] == '#')
        //     continue;

        for (int i = 0; i < 4; i++) {
            pair<int, int> new_point
                = make_pair(cur_point.first + dx[i], cur_point.second + dy[i]);
            if (grid[new_point.first][new_point.second] == '#')
                continue;
            grid[new_point.first][new_point.second] = '#';
            point.push(new_point);
            step.push(cur_step + 1);
            direction[new_point.first][new_point.second] = i;
            // route.push(cur_route + dir[i]);
        }
    }
    cout << "NO\n";

    return 0;
}