#include <map>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, m, t;
    map<int, int> h;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        h[t] += 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        auto iter = h.lower_bound(t);
        if (iter->first != t) {
            if (iter == h.begin()) {
                cout << "-1\n";
                continue;
            } else iter--;
        }
        cout << iter->first << "\n";
        if (iter->second == 1) h.erase(iter);
        else iter->second -= 1;
    }
    return 0;
}