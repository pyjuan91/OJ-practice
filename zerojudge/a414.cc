#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        if (n & 1) {
            int cnt = 0;
            while (n & 1) {
                cnt += 1;
                n >>= 1;
            }
            cout << cnt << "\n";
        } else
            cout << 0 << "\n";
    }
    return 0;
}