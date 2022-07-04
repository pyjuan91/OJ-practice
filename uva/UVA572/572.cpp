// #include <cstring>
// #include <iostream>
// using namespace std;
// char graph[105][105];
// int cmp[105][105], n, m, si, sj, cnt;
// const int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
//           dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// void check(int i, int j) {
//    cmp[i][j] = 0;
//    for (int k = 0; k < 8; k++) {
//       int ni = i + di[k], nj = j + dj[k];
//       if (ni >= 0 && ni < n && nj >= 0 && nj < m && cmp[ni][nj]) {
//          check(ni, nj);
//       }
//    }
// }
// int main(void) {
//    while (cin >> n >> m && n) {
//       cnt = 0;
//       memset(cmp, 0, sizeof(cmp));
//       for (int i = 0; i < n; i++) {
//          for (int j = 0; j < m; j++) {
//             cin >> graph[i][j];
//             if (graph[i][j] == '@')
//                cmp[i][j] = 1;
//          }
//       }
//       for (;;) {
//          si = sj = 105;
//          for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                if (cmp[i][j] == 1) {
//                   si = i, sj = j;
//                   break;
//                }
//             }
//          }
//          if (si == sj && si == 105) {
//             cout << cnt << endl;
//             break;
//          }
//          cnt++;
//          check(si, sj);
//       }
//    }
//    return 0;
// }

#include <cstdio>
#include <cstring>
const int maxn = 100 + 5;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id) {
   if (r < 0 || r >= m || c < 0 || c >= n)
      return;
   if (idx[r][c] > 0 || pic[r][c] != '@')
      return;
   idx[r][c] = id;
   for (int dr = -1; dr <= 1; dr++)
      for (int dc = -1; dc <= 1; dc++)
         if (dr != 0 || dc != 0)
            dfs(r + dr, c + dc, id);
}

int main() {
   while (scanf("%d%d", &m, &n) == 2 && m && n) {
      for (int i = 0; i < m; i++)
         scanf("%s", pic[i]);
      memset(idx, 0, sizeof(idx));
      int cnt = 0;
      for (int i = 0; i < m; i++)
         for (int j = 0; j < n; j++)
            if (idx[i][j] == 0 && pic[i][j] == '@')
               dfs(i, j, ++cnt);
      printf("%d\n", cnt);
   }
   return 0;
}