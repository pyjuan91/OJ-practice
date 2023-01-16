#include <cstdio>
#include <vector>
using namespace std;
const int d[2][4][2] = {
    { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } },
    { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }
};
int main(void)
{
    int t, n, m, cur_dir;
    scanf("%d", &t);
    while (t--) {
        cur_dir = 0;
        scanf("%d%d", &n, &m);
        vector<vector<int>> a(n, vector<int>(n));
        pair<int, int> cur, neo;
        cur = { 0, 0 };
        a[0][0] = 1;
        for (int i = 2; i <= n * n; i++) {
            neo = { cur.first + d[m - 1][cur_dir][0],
                cur.second + d[m - 1][cur_dir][1] };
            while (neo.first < 0 || neo.first >= n || neo.second < 0 || neo.second >= n || a[neo.first][neo.second]) {
                cur_dir = (cur_dir + 1) % 4;
                neo = { cur.first + d[m - 1][cur_dir][0],
                    cur.second + d[m - 1][cur_dir][1] };
            }
            a[neo.first][neo.second] = i;
            cur = neo;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%5d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}