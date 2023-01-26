#include <vector>
#include "iostream"
#include "set"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, x, res = 0, head = 0;
    set<int> s;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
        while (s.find(x) != s.end()) s.erase(a[head++]);
        s.insert(x);
        res = max((int) s.size(), res);
    }
    cout << res;
    return 0;
}