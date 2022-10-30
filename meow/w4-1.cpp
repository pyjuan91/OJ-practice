#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class node {
public:
    int val, index;
    node(int val, int index)
    {
        this->val = val;
        this->index = index;
    }

    bool operator<(const node& b) const
    {
        return val < b.val;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<node> a;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        node nd(val, i);
        a.push_back(nd);
    }

    sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    while (left < right) {
        ll sum = a[left].val + a[right].val;
        if (sum == (long long)s) {
            cout << a[left].index + 1 << " " << a[right].index + 1 << "\n";
            return 0;
        } else if (sum > (long long)s) {
            right--;
        } else {
            left++;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}