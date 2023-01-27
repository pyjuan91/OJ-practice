#include <set>
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int x, n, p;
    set<int> lights;
    multiset<int> len;
    cin >> x >> n;
    lights.insert(0);
    lights.insert(x);
    len.insert(x);
    for (int i = 0; i < n; i++) {
        cin >> p;
        auto right = lights.upper_bound(p);
        auto left = right;
        left--;
        len.erase(len.find(*right - *left));
        len.insert(*right - p);
        len.insert(p - *left);
        lights.insert(p);
        auto ans = len.end();
        ans--;
        cout << *ans << "\n";
    }
    return 0;
}