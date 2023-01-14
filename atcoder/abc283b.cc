#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n, q, cmd, k, x;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> q;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> k >> x;
            a[k] = x;
        } else {
            cin >> k;
            cout << a[k] << "\n";
        }
    }
}