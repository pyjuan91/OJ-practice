#include "bits/stdc++.h"

using namespace std;

class Ranges {
public:
    int id, x, y;

    Ranges() {
        id = x = y = 0;
    }

    Ranges(int _id, int _x, int _y) {
        id = _id;
        x = _x;
        y = _y;
    }

    bool operator<(const Ranges &b) const {
        if (x == b.x) return y > b.y;
        return x < b.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, x, y, ma, mi;
    vector<Ranges> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a.emplace_back(i, x, y);
    }
    sort(a.begin(), a.end());
    vector<bool> beCont(n), cont(n);
    ma = -1;
    for (auto r: a) {
        beCont[r.id] = r.y <= ma;
        ma = max(ma, r.y);
    }
    mi = 2e9;
    reverse(a.begin(), a.end());
    for (auto r: a) {
        cont[r.id] = r.y >= mi;
        mi = min(mi, r.y);
    }
    for (auto i: cont) cout << i << " ";
    cout << endl;
    for (auto i: beCont) cout << i << " ";
    return 0;
}