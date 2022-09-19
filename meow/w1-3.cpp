#include <bits/stdc++.h>
using namespace std;
void helper(int n, int left, int mid, int right);
int cnt = 0;
queue<int> L, R;
int main(void)
{
    int n;
    cin >> n;
    helper(n, 1, 2, 3);
    cout << cnt << "\n";
    while (!L.empty()) {
        cout << L.front() << " " << R.front() << "\n";
        L.pop();
        R.pop();
    }
    return 0;
}
void helper(int n, int left, int mid, int right)
{
    if (n <= 0)
        return;
    helper(n - 1, left, right, mid);
    cnt++;
    L.push(left);
    R.push(right);
    helper(n - 1, mid, left, right);
}