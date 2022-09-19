#include <bits/stdc++.h>
using namespace std;
int sel[20];
long long mi = INT_MAX, diff = 0;
void helper(vector<int>& v, int selected, int size)
{
    if (selected == size) {
        diff = 0;
        for (int i = 0; i < size; i++) {
            if (sel[i])
                diff += (long long)v[i];
            else
                diff -= (long long)v[i];
        }
        mi = min(mi, llabs(diff));
        return;
    }
    helper(v, selected + 1, size);
    sel[selected] = 1;
    helper(v, selected + 1, size);
    sel[selected] = 0;
}
int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sel[i] = 0;
    }
    helper(v, 0, n);
    cout << mi << "\n";
    return 0;
}