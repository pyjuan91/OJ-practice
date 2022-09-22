#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int t, n, k, e;
    long long sc;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        sc = 0;
        vector<int> v(k);
        for (int i = 0; i < n; i++) {
            cin >> e;
            v[i % k] = max(v[i % k], e);
        }
        for (int i = 0; i < k; i++)
            sc += (long long)v[i];
        cout << sc << "\n";
    }
    return 0;
}