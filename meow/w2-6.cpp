#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int sudo[81], row[9][10], col[9][10], grid[3][3][10];
bool input(void);
void init(void);
void output(void);
bool solve(int cur);
bool checkValid(int cur, int num);
void update(int r, int c, int num, int val);
bool checkAll(void)
{
    for (int cur = 0; cur < 81; cur++) {
        if (sudo[cur] == 0)
            continue;
        if (!checkValid(cur, sudo[cur]))
            return false;
        update(cur / 9, cur % 9, sudo[cur], 1);
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (input()) {
        init();
        if (!checkAll()) {
            cout << "No solution.\n";
            continue;
        }
        if (!solve(0)) {
            cout << "No solution.\n";
        }
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
bool solve(int cur)
{
    if (cur == 81) {
        output();
        return true;
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
                if (solve(cur + 1))
                    return true;
                row[r][i] = col[c][i] = grid[gi][gj][i] = 0;
            }
        }
        sudo[cur] = 0;
        return false;
    } else {
        return solve(cur + 1);
    }
}
void update(int r, int c, int num, int val)
{
    row[r][num] = val;
    col[c][num] = val;
    grid[r/3][c/3][num] = val;
}