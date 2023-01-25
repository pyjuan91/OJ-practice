#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, x, v;
    cin >> n >> x;
    if (n == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        a.emplace_back(v, i);
    }
    sort(a.begin(), a.end());
    int left = 0, right = n - 1;
    while (left + 1 < right) {
        if (a[left].first + a[right].first == x) break;
        else if (a[left].first + a[right].first < x) left += 1;
        else right -= 1;
    }

    if (a[left].first + a[right].first == x)
        cout << a[left].second << " " << a[right].second << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}