#include <iostream>
using namespace std;
int main(void)
{
    int t, n, m, sx, sy, d;
    cin >> t;
    while (t--) {
        cin >> n >> m >> sx >> sy >> d;
        if ((sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m)
            || (sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m)) {
            cout << -1 << "\n";
        } else {
            cout << n + m - 2 << endl;
        }
    }
    return 0;
}