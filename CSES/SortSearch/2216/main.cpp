#include <vector>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, res = 0, x;
    cin >> n;
    vector<bool> a(n + 1, false);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!a[x - 1]) res += 1;
        a[x] = true;
    }
    cout << res;
    return 0;
}