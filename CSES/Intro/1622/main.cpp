#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    string str;
    cin >> str;
    vector<char> s;
    vector<string> res;
    for (auto c: str) s.emplace_back(c);
    sort(s.begin(), s.end());
    do {
        string neo = {s.begin(), s.end()};
        res.emplace_back(neo);
    } while (next_permutation(s.begin(), s.end()));

    cout << res.size() << "\n";
    for (auto &i: res) cout << i << "\n";
    return 0;
}