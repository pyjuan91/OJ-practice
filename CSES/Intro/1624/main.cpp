#include "iostream"

using namespace std;

char b[8][8] = {};
int res = 0;
bool diag[20] = {};
bool antiDiag[20] = {};
bool col[8] = {};

void solve(int curRow) {
    if (curRow == 8) {
        res += 1;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (col[i] || antiDiag[curRow - i + 8]
            || diag[curRow + i] || b[curRow][i] == '*')
            continue;
        col[i] = antiDiag[curRow - i + 8] = diag[curRow + i] = true;
        solve(curRow + 1);
        col[i] = antiDiag[curRow - i + 8] = diag[curRow + i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    for (auto &i: b)
        for (char &j: i)
            cin >> j;
    solve(0);
    cout << res;
    return 0;
}