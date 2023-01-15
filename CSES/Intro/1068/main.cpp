#include "bits/stdc++.h"

using namespace std;

int main(void) {
    long long n;
    cin >> n;
    for (;;) {
        cout << n << " ";
        if (n == 1) break;
        if (n % 2 == 1) n = n * 3 + 1;
        else n /= 2;
    }
    return 0;
}