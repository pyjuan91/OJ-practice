#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
char a[8][8];
int row[8], col[8], diag[15], antiDiag[15];
int cnt;
void input(void);
void init(void);
void output(void);
void backTracking(int cur);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    init();
    backTracking(0);
    cout << cnt << "\n";
    return 0;
}
void input(void)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> a[i][j];
}
void init(void)
{
    cnt = 0;
    memset(row, 0, 32);
    memset(col, 0, 32);
    memset(diag, 0, 60);
    memset(antiDiag, 0, 60);
}
void output(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
void backTracking(int cur)
{
    if (cur == 8) {
        cnt++;
        // output();
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (a[cur][i] == '.' && col[i] == 0
            && diag[cur - i + 7] == 0 && antiDiag[cur + i] == 0) {
            col[i] = diag[cur - i + 7] = antiDiag[cur + i] = 1;
            // char c = a[cur][i];
            // a[cur][i] = 'q';
            backTracking(cur + 1);
            col[i] = diag[cur - i + 7] = antiDiag[cur + i] = 0;
            // a[cur][i] = c;
        }
    }
}