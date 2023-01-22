#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        bool cond1 = (2 * a - b) % 3 == 0;
        bool cond2 = (2 * b - a) % 3 == 0;
        bool cond3 = (2 * a - b) >= 0;
        bool cond4 = (2 * b - a) >= 0;
        if (cond1 && cond2 && cond3 && cond4) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}