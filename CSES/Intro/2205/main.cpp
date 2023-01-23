#include <vector>
#include "iostream"

using namespace std;

vector<string> solve(int n) {
    vector<string> last;
    if (n <= 1) return {"0", "1"};
    last = solve(n - 1);
    vector<string> res;
    for (auto &i: last) res.push_back("0" + i);
    for (auto iter = last.rbegin(); iter != last.rend(); iter++)
        res.push_back("1" + *iter);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    vector<string> res = solve(n);
    for (auto &i: res) cout << i << "\n";
    return 0;
}