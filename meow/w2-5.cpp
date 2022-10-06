#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
using namespace std;
class Point {
public:
    int i, j;
    Point() { }
    Point(int i, int j)
        : i(i)
        , j(j)
    {
    }

    bool operator==(const Point& p) const
    {
        return i == p.i && j == p.j;
    }
};

int N, R, C;
int hive[12][7], used[12][7];
Point two[2], three[2];
int mincost;
static const int di[4] = { 0, -1, 0, 1 };
static const int dj[4] = { 1, 0, -1, 0 };

void input(void);
void compute(void);
void dfs(int, int, int, int);
int bfs(void);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        input();
    }
    return 0;
}
void input(void)
{
    cin >> R >> C;

    for (int i = 0; i < R + 2; i++)
        used[i][0] = used[i][R + 1] = 1;
    for (int j = 0; j < C + 2; j++)
        used[0][j] = used[C + 1][j] = 1;

    cin >> two[0].i >> two[0].j;
    cin >> two[1].i >> two[1].j;
    cin >> three[0].i >> three[0].j;
    cin >> three[1].i >> three[1].j;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            used[i][j] = 0;
            cin >> hive[i][j];
        }
    }
}

void dfs(int i, int j, int dist, int pre)
{
    if (i == two[1].i && j == two[1].j) {
        mincost = min(mincost, dist + bfs());
        return;
    }

    if (dist /*+ manhattanDist(i, j)*/ > mincost)
        return;

    if (pre != -1) {
        for (int r = 0; r < 4; r++) {
            if (r == pre)
                continue;
            if (i + di[r] == two[1].i && j + dj[r] == two[1].j)
                continue;
            if (G[i + di[r]][j + dj[r]] == TWO)
                return;
        }
    }

    G[i][j] = TWO;

    if (cut(i, j))
        return;

    int ni, nj;
    for (int d = 0; d < 4; d++) {
        ni = i + di[d];
        nj = j + dj[d];
        char target = G[ni][nj];
        if (target == EMPTY || (ni == two[1].i && nj == two[1].j)) {
            dfs(ni, nj, dist + 1, (d + 2) % 4);
            G[ni][nj] = target;
        }
    }
}

void compute(void)
{
    mincost = INT32_MAX;
    dfs(two[0].i, two[0].j, 0, -1);
    if (mincost >= INT32_MAX)
        cout << 0 << endl;
    else
        cout << mincost << endl;
}