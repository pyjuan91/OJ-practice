#include <vector>
#include "iostream"
#include "algorithm"
#include "queue"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, a, b, res = 1, cur = 1;

    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<>> out;
    out.push(v[0].second);
    for (int i = 1; i < n; i++) {
        while (!out.empty() && v[i].first >= out.top()) {
            out.pop();
            cur -= 1;
        }
        cur += 1;
        res = max(res, cur);
        out.push(v[i].second);
    }
    cout << res;
    return 0;
}