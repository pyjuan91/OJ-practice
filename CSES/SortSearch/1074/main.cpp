#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    long long res = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) res += 1LL * abs(a[i] - a[n / 2]);
    cout << res;
    return 0;
}