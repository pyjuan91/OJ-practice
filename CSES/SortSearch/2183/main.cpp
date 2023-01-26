#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
#define int long long
    int n, res = 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n && a[i] <= res; i++) res += a[i];
    cout << res;
    return 0;
}