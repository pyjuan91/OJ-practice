#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define INFTY (1 << 15)
#define MAX 9
#define EMPTY '0'
#define OBSTACLE '1'
#define TWO '2'
#define THREE '3'

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

int N, M;
char G[MAX + 2][MAX + 2];
Point two[2], three[2];
int mincost;
static const int di[4] = { 0, -1, 0, 1 };
static const int dj[4] = { 1, 0, -1, 0 };

int bfs()
{
    int D[MAX + 2][MAX + 2];
    queue<Point> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            D[i][j] = INFTY;
    }

    Q.push(Point(three[0].i, three[0].j));
    D[three[0].i][three[0].j] = 0;

    Point u, v;
    int ni, nj;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u == three[1])
            return D[u.i][u.j];
        for (int d = 0; d < 4; d++) {
            ni = u.i + di[d];
            nj = u.j + dj[d];
            if (D[ni][nj] == INFTY && (G[ni][nj] == EMPTY || G[ni][nj] == THREE)) {
                D[ni][nj] = D[u.i][u.j] + 1;
                Q.push(Point(ni, nj));
            }
        }
    }

    return INFTY;
}

int manhattanDist(int i, int j)
{
    return max(i, two[1].i) - min(i, two[1].i) + max(j, two[1].j) - min(j, two[1].j);
}

int getWidth(int i, int j, int d)
{
    int w = 0;
    while (1) {
        if (G[i][j] == TWO)
            return w;
        if (G[i][j] != EMPTY)
            return -1;
        i += di[d];
        j += dj[d];
        w++;
    }
}

bool isSeq(int i, int j, int d, int w, char ch)
{
    for (int s = 0; s < w; s++, i += di[d], j += dj[d]) {
        if (G[i][j] != ch)
            return false;
    }
    return true;
}

bool cut(int i, int j)
{
    for (int d = 0; d < 4; d++) {
        int w = getWidth(i + di[d], j + dj[d], d);
        if (w <= 0)
            continue;
        if (w == 1 || w == 2) {
            if (isSeq(i + di[(d + 1) % 4], j + dj[(d + 1) % 4], d, w + 2, TWO) || isSeq(i + di[(d + 3) % 4], j + dj[(d + 3) % 4], d, w + 2, TWO))
                return true;
        } else {
            if (isSeq(i + di[(d + 1) % 4], j + dj[(d + 1) % 4], d, w + 2, TWO) && isSeq(i + di[(d + 3) % 4] * 2, j + dj[(d + 3) % 4] * 2, d, w, EMPTY) || isSeq(i + di[(d + 3) % 4], j + dj[(d + 3) % 4], d, w + 2, TWO) && isSeq(i + di[(d + 1) % 4] * 2, j + dj[(d + 1) % 4] * 2, d, w, EMPTY)) {
                return true;
            }
        }
    }

    return false;
}

void dfs(int i, int j, int dist, int pre)
{
    if (i == two[1].i && j == two[1].j) {
        mincost = min(mincost, dist + bfs());
        return;
    }

    if (dist + manhattanDist(i, j) > mincost)
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

void compute()
{
    mincost = INFTY;
    dfs(two[0].i, two[0].j, 0, -1);
    if (mincost >= INFTY)
        cout << 0 << endl;
    else
        cout << mincost << endl;
}

bool input()
{
    cin >> N >> M;
    if (N == 0 && M == 0)
        return false;
    for (int i = 0; i < N + 2; i++)
        G[i][0] = G[i][M + 1] = OBSTACLE;
    for (int j = 0; j < M + 2; j++)
        G[0][j] = G[N + 1][j] = OBSTACLE;

    int s2c, s3c;
    s2c = s3c = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> G[i][j];
            if (G[i][j] == TWO)
                two[s2c++] = Point(i, j);
            if (G[i][j] == THREE)
                three[s3c++] = Point(i, j);
        }
    }
    return true;
}

int main()
{
    while (input())
        compute();
    return 0;
}