#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
int main(void)
{
    int n, cs;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    pair<int, int> cur;
    queue<pair<int, int>> q;
    queue<int> step;
    q.push({ 1, 1 });
    step.push(1);
    while (q.size()) {
        cur = q.front();
        q.pop();
        cs = step.front();
        step.pop();
        if (cur.first == n - 2 && cur.second == n - 2) {
            cout << cs;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx == -1 || nx == n || ny == -1 || ny == n || g[nx][ny] == '#')
                continue;
            g[nx][ny] = '#';
            q.push({ nx, ny });
            step.push(cs + 1);
        }
    }
    cout << "No solution!";
    return 0;
}