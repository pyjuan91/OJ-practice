#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int hive[12][7];
bool vist[12][7];
const int dx[6] = { 0, 0, -1, -1, 1, 1 };
const int dyEven[6] = { -1, 1, 0, 1, 0, 1 };
const int dyOdd[6] = { -1, 1, -1, 0, -1, 0 };
int helper(int r, int c, int st_r, int st_c,
    int cur_r, int cur_c, int des_r, int des_c, vector<pair<int,int>> v)
{
    if (cur_r == des_r && cur_c == des_c)
        return hive[des_r][des_c];
    // if (vist[cur_r][cur_c] && (cur_r != st_r || cur_c != st_c))
    //     return INT_MAX;

    bool isEven = ((cur_r % 2) == 0);
    int mi = INT_MAX;
    int cv, route_r, route_c;
    printf("cur: %d %d, val: %d\n", cur_r, cur_c, hive[cur_r][cur_c]);
    for (int i = 0; i < 6; i++) {
        int nx = cur_r + dx[i];
        int ny = cur_c + (isEven ? dyEven[i] : dyOdd[i]);

        if (nx < 1 || nx > r || ny < 1 || ny > c
            || (vist[nx][ny] && (nx != des_r || ny != des_c)))
            continue;

        printf("new: %d %d, val: %d\n", nx, ny, hive[nx][ny]);

        vist[nx][ny] = true;
        cv = helper(r, c, st_r, st_c, nx, ny, des_r, des_c);
        vist[nx][ny] = false;

        if (cv < mi) {
            mi = cv;
            route_r = nx;
            route_c = ny;
        }
    }
    if (mi == INT_MAX) {
        return INT_MAX;
    } else {
        // vist[route_r][route_c] = true;
        return hive[cur_r][cur_c] + mi;
    }
}
int main(void)
{
    int n, r, c, r1, r2, r3, r4, c1, c2, c3, c4;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &r, &c);
        scanf("%d%d%d%d%d%d%d%d",
            &r1, &r2, &r3, &r4, &c1, &c2, &c3, &c4);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                scanf("%d", &hive[i][j]);
                vist[i][j] = false;
            }
        }
        long long ans1, ans2;
        vist[r1][r2] = vist[r3][r4] = vist[c1][c2] = vist[c3][c4] = true;
        ans1 = helper(r, c, r1, r2, r1, r2, r3, r4);
        //     + helper(r, c, c1, c2, c1, c2, c3, c4);
        // memset(vist, false, sizeof(vist));
        // vist[r1][r2] = vist[r3][r4] = vist[c1][c2] = vist[c3][c4] = true;
        // ans2 = helper(r, c, c1, c2, c1, c2, c3, c4)
        //     + helper(r, c, r1, r2, r1, r2, r3, r4);
        // if (ans1 >= INT_MAX && ans2 >= INT_MAX) {
        //     printf("-1\n");
        //     continue;
        // }
        // printf("%lld\n", min(ans1, ans2));
        printf("%lld\n", ans1);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                printf(" %d", vist[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}