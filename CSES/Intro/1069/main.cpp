#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie();
    string dna;
    cin >> dna;
    int res = 1, cur, i = 0;
    while (i < dna.length()) {
        cur = 1;
        while (i + cur < dna.length()) {
            if (dna[i + cur] == dna[i]) cur++;
            else break;
        }
        res = max(res, cur);
        i = i + cur;
    }
    cout << res;
    return 0;
}