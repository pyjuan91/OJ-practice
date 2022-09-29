#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int sudo[81], row[9][10], col[9][10], grid[3][3][10];
bool hasSol;
bool input(void);
void init(void);
void output(void);
void solve(int cur);
bool checkValid(int cur, int num);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (input()) {
        init();
        solve(0);
        if (!hasSol)
            cout << "No solution\n";
    }
    return 0;
}
bool input(void)
{
    string str;
    cin >> str;
    if (str == "end")
        return false;
    for (int i = 0; i < 81; i++) {
        if (str[i] == '.')
            sudo[i] = 0;
        else
            sudo[i] = str[i] - '0';
    }
    return true;
}
void init(void)
{
    hasSol = false;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(grid, 0, sizeof(grid));
}
void output(void)
{
    for (int i = 0; i < 81; i++)
        cout << sudo[i];
    cout << "\n";
}
bool checkValid(int cur, int num)
{
    int r = cur / 9;
    int c = cur % 9;
    int gi = r / 3;
    int gj = c / 3;

    return !row[r][num] && !col[c][num] && !grid[gi][gj][num];
}
void solve(int cur)
{
    if (hasSol)
        return;
    if (cur == 81) {
        if (!hasSol)
        output();
        hasSol = true;
        return;
    }

    int r = cur / 9;
    int c = cur % 9;
    int gi = r / 3;
    int gj = c / 3;

    if (sudo[cur] == 0) {
        for (int i = 1; i < 10; i++) {
            if (checkValid(cur, i)) {
                sudo[cur] = i;
                row[r][i] = col[c][i] = grid[gi][gj][i] = 1;
                solve(cur + 1);
                row[r][i] = col[c][i] = grid[gi][gj][i] = 0;
            }
            if (hasSol)
                return;
        }
        sudo[cur] = 0;
        if (!hasSol)
            return;
    } else if (checkValid(cur, sudo[cur])) {
        row[r][sudo[cur]] = col[c][sudo[cur]] = grid[gi][gj][sudo[cur]] = 1;
        solve(cur + 1);
        row[r][sudo[cur]] = col[c][sudo[cur]] = grid[gi][gj][sudo[cur]] = 0;
    }
}