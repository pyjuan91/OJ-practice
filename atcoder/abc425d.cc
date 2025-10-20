#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a)
        cin >> x;
    queue<pair<int, int>> q;
    const int dx[] = { 1, -1, 0, 0 };
    const int dy[] = { 0, 0, 1, -1 };

    vector cnt(n, vector<int>(m, 0));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                q.push({ i, j });
                res++;
                for (int dir = 0; dir < 4; dir++)
                {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                        continue;
                    cnt[ni][nj]++;
                }
            }
        }
    }

    while (!q.empty())
    {
        vector<pair<int, int>> update_adj;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (a[nx][ny] == '.' && cnt[nx][ny] == 1)
                {
                    update_adj.push_back({ nx, ny });
                }
            }
        }
        debug(update_adj);
        for (auto [x, y] : update_adj)
        {
            q.push({ x, y });
            a[x][y] = '#';
            res++;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                cnt[nx][ny]++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}
