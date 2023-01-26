#include <set>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, x;
    multiset<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        auto iter = s.upper_bound(x);
        if (iter != s.end())s.erase(iter);
        s.insert(x);
    }
    cout << s.size();
    return 0;
}