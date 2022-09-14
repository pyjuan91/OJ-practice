#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char board[10][10];
bool helper(int i, int j)
{
    int left, right, up, down, di1, dj1, di2, dj2, num, lc, rc, uc, dc;
    left = j - 1, right = j + 1;
    lc = rc = 1;
    num = 4;
    while (true) {
        if (lc && left >= 0 && board[i][left] == 'X') {
            left--;
            num--;
        } else {
            lc = 0;
        }
        if (rc && right < 10 && board[i][right] == 'X') {
            right++;
            num--;
        } else {
            rc = 0;
        }
        if (lc == 0 && rc == 0)
            break;
    }
    if (num <= 0)
        return true;
    up = i + 1, down = i - 1;
    uc = dc = 1;
    num = 4;
    while (true) {
        if (uc && up < 10 && board[up][j] == 'X') {
            up++;
            num--;
        } else {
            uc = 0;
        }
        if (dc && down >= 0 && board[down][j] == 'X') {
            down--;
            num--;
        } else {
            dc = 0;
        }
        if (uc == 0 && dc == 0)
            break;
    }
    if (num <= 0)
        return true;
    di1 = i - 1, dj1 = j - 1;
    di2 = i + 1, dj2 = j + 1;
    uc = dc = 1;
    num = 4;
    while (true) {
        if (uc && di1 >= 0 && dj1 >= 0 && board[di1][dj1] == 'X') {
            di1--, dj1--;
            num--;
        } else {
            uc = 0;
        }
        if (dc && di2 < 10 && dj2 < 10 && board[di2][dj2] == 'X') {
            di2++, dj2++;
            num--;
        } else {
            dc = 0;
        }
        if (uc == 0 && dc == 0)
            break;
    }
    if (num <= 0)
        return true;
    di1 = i - 1, dj1 = j + 1;
    di2 = i + 1, dj2 = j - 1;
    uc = dc = 1;
    num = 4;
    while (true) {
        if (uc && di1 >= 0 && dj1 < 10 && board[di1][dj1] == 'X') {
            di1--, dj1++;
            num--;
        } else {
            uc = 0;
        }
        if (dc && di2 < 10 && dj2 >= 0 && board[di2][dj2] == 'X') {
            di2++, dj2--;
            num--;
        } else {
            dc = 0;
        }
        if (uc == 0 && dc == 0)
            break;
    }
    if (num <= 0)
        return true;
    return false;
}
bool crossCanWin(void)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == '.' && helper(i, j)) {
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }
    if (crossCanWin())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}