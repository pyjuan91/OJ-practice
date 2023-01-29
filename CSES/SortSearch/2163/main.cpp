#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, k, cur = 0, kill;
    cin >> n >> k;
    ordered_set<int> children;
    for (int i = 1; i <= n; i++) children.insert(i);
    while (!children.empty()) {
        cur %= (int) children.size();
        kill = (cur + k) % (int) children.size();
        cur = kill;
        auto iter = children.find_by_order(kill);
        cout << *iter << " ";
        children.erase(iter);
    }
    return 0;
}