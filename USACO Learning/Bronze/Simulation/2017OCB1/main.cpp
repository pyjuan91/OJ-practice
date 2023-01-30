#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ::freopen("lostcow.in", "r", stdin);
    ::freopen("lostcow.out", "w", stdout);
    int x, y, res = 0, dis = 1, dir = 1;
    cin >> x >> y;
    while (true) {
        int nx = x + dis * dir;
        if (dir == 1 && y <= nx && y > x) {
            res += y - x;
            break;
        } else if (dir == -1 && y >= nx && y < x) {
            res += x - y;
            break;
        } else if (dir == 1) res += 2 * (nx - x);
        else res += 2 * (x - nx);
        dir = 0 - dir;
        dis <<= 1;
    }
    cout << res;
    return 0;
}