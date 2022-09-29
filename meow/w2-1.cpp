// #include <algorithm>
// #include <cstring>
// #include <iostream>
// using namespace std;
// char route[48];
// const char dir[4] = { 'U', 'D', 'L', 'R' };
// int map[7][7];
// bool record[7][7][4];
// int U, D, L, R, cnt;
// void input(void);
// void init(void);
// bool helper(int cur, int x, int y);
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     input();
//     init();
//     helper(0, 0, 0);
//     cout << cnt << "\n";
//     return 0;
// }
// void input(void)
// {
//     for (int i = 0; i < 48; i++)
//         cin >> route[i];
// }
// void init(void)
// {
//     U = D = L = R = cnt = 0;
//     memset(map, 0, sizeof(map));
//     map[0][0] = 1;
//     memset(record, true, sizeof(record));
// }
// bool helper(int cur, int x, int y)
// {
//     if (x == 6 && y == 0) {
//         if (cur == 48) {
//             cnt++;
//             return true;
//         }
//         // reach too early
//         // opt 1
//         return false;
//     }
//     if (cur == 48) {
//         return false;
//     }

//     bool checker = false;
//     cout << x << " " << y << endl;
//     if (route[cur] == '?') {
//         if (x > 0 && map[x - 1][y] == 0 && record[x - 1][y][1]) {
//             map[x - 1][y] = 1;
//             checker |= helper(cur + 1, x - 1, y);
//             map[x - 1][y] = 0;
//         }
//         if (x < 6 && map[x + 1][y] == 0 && record[x + 1][y][0]) {
//             map[x + 1][y] = 1;
//             checker |= helper(cur + 1, x + 1, y);
//             map[x + 1][y] = 0;
//         }
//         if (y > 0 && map[x][y - 1] == 0 && record[x][y - 1][3]) {
//             map[x][y - 1] = 1;
//             checker |= helper(cur + 1, x, y - 1);
//             map[x][y - 1] = 0;
//         }
//         if (y < 6 && map[x][y + 1] == 0 && record[x][y + 1][2]) {
//             map[x][y + 1] = 1;
//             checker |= helper(cur + 1, x, y + 1);
//             map[x][y + 1] = 0;
//         }
//     } else {
//         if (route[cur] == 'L' && y && map[x][y - 1] == 0 && record[x][y - 1][3]) {
//             map[x][y - 1] = 1;
//             checker |= helper(cur + 1, x, y - 1);
//             map[x][y - 1] = 0;
//         } else if (route[cur] == 'R' && y < 6 && map[x][y + 1] == 0 && record[x][y + 1][2]) {
//             map[x][y + 1] = 1;
//             checker |= helper(cur + 1, x, y + 1);
//             map[x][y + 1] = 0;
//         } else if (route[cur] == 'U' && x && map[x - 1][y] == 0 && record[x - 1][y][1]) {
//             map[x - 1][y] = 1;
//             checker |= helper(cur + 1, x - 1, y);
//             map[x - 1][y] = 0;
//         } else if (route[cur] == 'D' && x < 6 && map[x + 1][y] == 0 && record[x + 1][y][0]) {
//             map[x + 1][y] = 1;
//             checker |= helper(cur + 1, x + 1, y);
//             map[x + 1][y] = 0;
//         }
//     }
//     record[x][y]
//     return checker;
// }

#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
int map[7][7];
char path[48];
void input(void);
int backTracking(int cur, int r, int c);
int main(void)
{
    // clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    memset(map, 0, sizeof(map));
    cout << backTracking(0, 0, 0) << "\n";
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
void input(void)
{
    for (int i = 0; i < 48; i++) {
        cin >> path[i];
    }
    return;
}
int backTracking(int cur, int r, int c)
{
    // the brand-new optimalizm
    if ((r == 0 || map[r - 1][c]) && (r == 6 || map[r + 1][c])
        && (!(c == 0 || map[r][c - 1]) && !(c == 6 || map[r][c + 1])))
        return 0;
    if ((c == 0 || map[r][c - 1]) && (c == 6 || map[r][c + 1])
        && (!(r == 6 || map[r + 1][c]) && !(r == 0 || map[r - 1][c])))
        return 0;

    if (r == 6 && c == 0) {
        if (cur == 48)
            return 1;
        return 0;
    }

    if (cur == 48)
        return 0;

    int res = 0;
    map[r][c] = 1;

    if (path[cur] == '?') {
        if (r && !map[r - 1][c]) {
            res += backTracking(cur + 1, r - 1, c);
        }
        if (r < 6 && !map[r + 1][c]) {
            res += backTracking(cur + 1, r + 1, c);
        }
        if (c && !map[r][c - 1]) {
            res += backTracking(cur + 1, r, c - 1);
        }
        if (c < 6 && !map[r][c + 1]) {
            res += backTracking(cur + 1, r, c + 1);
        }
    } else {
        switch (path[cur]) {
        case 'U':
            if (r && !map[r - 1][c]) {
                res += backTracking(cur + 1, r - 1, c);
            }
            break;
        case 'D':
            if (r < 6 && !map[r + 1][c]) {
                res += backTracking(cur + 1, r + 1, c);
            }
            break;
        case 'L':
            if (c && !map[r][c - 1]) {
                res += backTracking(cur + 1, r, c - 1);
            }
            break;
        case 'R':
            if (c < 6 && !map[r][c + 1]) {
                res += backTracking(cur + 1, r, c + 1);
            }
            break;
        default:
            break;
        }
    }
    map[r][c] = 0;
    return res;
}