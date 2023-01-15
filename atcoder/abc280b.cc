#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cout << a[i] - a[i - 1] << " ";
    return 0;
}