#include <vector>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, cur = 0;
    vector<int> children;
    vector<bool> alive;
    cin >> n;
    for (int i = 0; i < n; i++) {
        children.emplace_back(i);
        alive.emplace_back(true);
    }
    for (int i = 1; i < n; i++) {
        do {
            cur++;
            cur %= n;
        } while (!alive[cur]);
        alive[cur] = false;
        cout << cur + 1 << " ";
        while (!alive[cur]) {
            cur++;
            cur %= n;
        }
    }
    cout << cur + 1;
    return 0;
}