#include <vector>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector<bool> v(1e9 + 1, false);
    int n, x, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!v[x]) res += 1;
        v[x] = true;
    }
    cout << res;
    return 0;
}