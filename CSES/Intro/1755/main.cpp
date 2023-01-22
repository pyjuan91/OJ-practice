#include <vector>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    string str;
    cin >> str;
    vector<int> map(26, 0);
    for (auto c: str) map[c - 'A'] += 1;
    int oddNum = 0, odd = -1;
    for (int i = 0; i < 26; i++) {
        if (map[i] % 2 == 1) {
            oddNum += 1;
            odd = i;
        }
    }
    if (oddNum > 1) cout << "NO SOLUTION\n";
    else {
        for (int i = 0; i < 26; i++) {
            if (i == odd) continue;
            for (int j = 0; j < map[i] / 2; j++)
                cout << (char) ('A' + i);
        }

        if (odd != -1)
            for (int j = 0; j < map[odd]; j++)
                cout << (char) ('A' + odd);

        for (int i = 25; i >= 0; i--) {
            if (i == odd) continue;
            for (int j = 0; j < map[i] / 2; j++)
                cout << (char) ('A' + i);
        }
    }
    return 0;
}