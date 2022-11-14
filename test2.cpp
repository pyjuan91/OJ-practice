#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int grid[1005][1005], dir[1005][1005];
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
const char direction[4] = { 'D', 'U', 'R', 'L' };
int cnt = 0;
vector<char> v;
void go(int ex, int ey, int sx, int sy)
{
    while (ex != sx || ey != sy) {
        cnt += 1;
        int tmpD = dir[ex][ey];
        v.push_back(direction[tmpD]);
        ex -= dx[tmpD];
        ey -= dy[tmpD];
    }
}
int main(void)
{
    fstream fin;
    fin.open("input.txt", ios::in);
#define cin fin
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    char c;

    pair<int, int> start;
    deque<pair<int, int>> dq;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '#') {
                grid[i][j] = 0;
            } else if (c == 'A') {
                if (j == 1 || j == m || i == 1 || i == n) {
                    cout << "YES\n"
                         << 0 << "\n"
                         << "\n\n";
                    return 0;
                }
                grid[i][j] = 2;
                start = { i, j };
            } else if (c == 'M') {
                grid[i][j] = 3;
                dq.push_back({ i, j });
            } else {
                if (j == 1 || j == m || i == 1 || i == n) {
                    grid[i][j] = 4;
                } else {
                    grid[i][j] = 1;
                }
            }
        }
    }

    dq.push_front(start);
    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        if (grid[cur.first][cur.second] == 2) {
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    dir[nx][ny] = i;
                    dq.push_back({ nx, ny });
                }
                if (grid[nx][ny] == 4) {
                    dir[nx][ny] = i;
                    go(nx, ny, start.first, start.second);
                    cout << "YES\n";
                    cout << cnt << "\n";
                    string str(v.rbegin(), v.rend());
                    cout << str << "\n";
                    return 0;
                }
            }
        } else if (grid[cur.first][cur.second] == 3) {
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (grid[nx][ny] == 1 || grid[nx][ny] == 2 || grid[nx][ny] == 4) {
                    grid[nx][ny] = 3;
                    dq.push_back({ nx, ny });
                }
            }
        }

        cout << cur.first << " " << cur.second << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "NO\n";
    return 0;
}