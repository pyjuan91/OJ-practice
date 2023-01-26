#include <vector>
#include "iostream"

using namespace std;

int calculate(int a, int b, vector<int> &pos) {
    int res = 0;
    if (abs(a - b) > 1) {
        if (pos[a + 1] < pos[a]) res += 1;
        if (pos[a - 1] > pos[a]) res += 1;
        if (pos[b + 1] < pos[b]) res += 1;
        if (pos[b - 1] > pos[b]) res += 1;
    } else {
        if (a == b + 1) {
            if (pos[a + 1] < pos[a]) res += 1;
            if (pos[b - 1] > pos[b]) res += 1;
            if (pos[a] < pos[b]) res += 1;
        } else {
            if (pos[b + 1] < pos[b]) res += 1;
            if (pos[a - 1] > pos[a]) res += 1;
            if (pos[b] < pos[a]) res += 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, m, a, b, x, res = 1, av, bv;
    cin >> n >> m;
    vector<int> pos(n + 2, 0), val(n + 2, 0);
    pos[n + 1] = val[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        val[i] = x;
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (pos[i + 1] < pos[i]) res += 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        av = val[a], bv = val[b];
        res -= calculate(av, bv, pos);
        swap(pos[av], pos[bv]);
        res += calculate(av, bv, pos);
        swap(val[a], val[b]);
        cout << res << "\n";
    }
    return 0;
}