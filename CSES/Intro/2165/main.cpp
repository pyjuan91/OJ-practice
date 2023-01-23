#include <vector>
#include "iostream"

using namespace std;
vector<int> L, R;

void solve(int n, int left, int mid, int right) {
    if (n <= 1) {
        L.emplace_back(left);
        R.emplace_back(right);
        return;
    }
    solve(n - 1, left, right, mid);
    solve(1, left, mid, right);
    solve(n - 1, mid, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    solve(n, 1, 2, 3);
    cout << L.size() << "\n";
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " " << R[i] << "\n";
    return 0;
}