// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <vector>
// using namespace std;
// int row[15], diag[25], antiDiag[25], diagForR[25], antiDiagForR[25];
// int Q, R, cnt, n;
// void backTracking(int curQ, int curR);
// void init(void);
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--) {
//         cin >> Q >> R;
//         init();
//         if (Q == 0 && R == 0) {
//             cout << "0\n";
//             continue;
//         }
//         backTracking(0, 0);
//         cout << cnt << "\n";
//     }
//     return 0;
// }
// void init(void)
// {
//     memset(row, 0, sizeof(row));
//     memset(diag, 0, sizeof(diag));
//     memset(antiDiag, 0, sizeof(antiDiag));
//     memset(diagForR, 0, sizeof(diagForR));
//     memset(antiDiagForR, 0, sizeof(antiDiagForR));
//     cnt = 0;
//     n = Q + R;
// }
// void backTracking(int curQ, int curR)
// {
//     if (curQ == Q && curR == R) {
//         cnt++;
//         return;
//     }

//     // put Q and trace
//     if (curQ < Q) {
//         for (int i = 0; i < n; i++) {
//             if (row[i] == 0 && diag[curR + curQ - i + n - 1] == 0
//                 && antiDiag[curR + curQ + i] == 0
//                 && diagForR[curR + curQ - i + n - 1] == 0
//                 && antiDiagForR[curR + curQ + i] == 0) {
//                 row[i] = diag[curR + curQ - i + n - 1] = antiDiag[curR + curQ + i] = 1;
//                 backTracking(curQ + 1, curR);
//                 row[i] = diag[curR + curQ - i + n - 1] = antiDiag[curR + curQ + i] = 0;
//             }
//         }
//     }

//     // put R and trace
//     if (curR < R) {
//         for (int i = 0; i < n; i++) {
//             if (row[i] == 0 && diag[curQ + curR - i + n - 1] == 0
//                 && antiDiag[curQ + curR + i] == 0) {
//                 row[i] = 1;
//                 diagForR[curR + curQ - i + n - 1] += 1;
//                 antiDiagForR[curR + curQ + i] += 1;
//                 backTracking(curQ, curR + 1);
//                 row[i] = 0;
//                 diagForR[curR + curQ - i + n - 1] -= 1;
//                 antiDiagForR[curR + curQ + i] -= 1;
//             }
//         }
//     }
// }

#include <iostream>
using namespace std;

int MASK;
int ans;
void dfs(int M, int L, int R, int LforRook, int RforRook, int Queen, int Rook);
int lowbit(int x);
int main(void)
{
    int q, r, n, t;
    cin >> t;
    while (t--) {
        cin >> q >> r;
        n = q + r;
        ans = 0;
        MASK = (1 << n) - 1;
        dfs(0, 0, 0, 0, 0, q, r);
        cout << ans << endl;
    }
    return 0;
}

int lowbit(int x)
{
    return x & -x;
}

void dfs(int M, int L, int R, int LforRook, int RforRook, int Queen, int Rook)
{
    if (M == MASK) {
        ans++;
        return;
    }

    // put Queen
    if (Queen) {
        int Legal = MASK & ~(M | L | R | LforRook | RforRook);
        for (int num = 0; Legal; Legal ^= num) {
            num = lowbit(Legal);
            dfs(M | num, (L | num) << 1, (R | num) >> 1,
                LforRook << 1, RforRook >> 1, Queen - 1, Rook);
        }
    }

    // put Rook
    if (Rook) {
        int Legal = MASK & ~(M | L | R);
        for (int num = 0; Legal; Legal ^= num) {
            num = lowbit(Legal);
            dfs(M | num, L << 1, R >> 1,
                (LforRook | num) << 1, (RforRook | num) >> 1, Queen, Rook - 1);
        }
    }
}
