#include <cstdio>
#include <vector>
using namespace std;
char map[1005][1005];
vector<pair<int, int>> dot;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
void dfs(int x, int y)
{
    if (map[x][y] == '#')
        return;
    map[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
}
void printMap(int n, int m)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(void)
{
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &map[i][j]);
            dot.push_back({ i, j });
        }
    }
    for (int i = 0; i <= n + 1; i++)
        map[i][0] = map[i][m + 1] = '#';
    for (int i = 0; i <= m + 1; i++)
        map[0][i] = map[n + 1][i] = '#';

    for (auto p : dot) {
        if (map[p.first][p.second] == '#')
            continue;
        ans += 1;
        dfs(p.first, p.second);
    }
    printf("%d\n", ans);
    return 0;
}