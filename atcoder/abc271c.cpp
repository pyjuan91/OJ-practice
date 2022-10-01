#include <bits/stdc++.h>
using namespace std;
int n, a[300005];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int buff, useless = 0, left, right;
    vector<bool> book(n + 2, false);
    for (int i = 0; i < n; i++) {
        cin >> buff;
        if (buff > n)
            useless++;
        else if (book[buff] == true)
            useless++;
        else
            book[buff] = true;
    }
    left = 1;
    right = n + 1;
    for (;;) {
        if (book[left]) {
            left++;
            continue;
        }
        while (right > 0 && book[right] == false) {
            right--;
        }

        if (useless > 1) {
            useless -= 2;
            book[left] = true;
        } else if (left < right) {
            book[right] = false;
            useless++;
        } else {
            break;
        }
    }
    std::cout << left - 1 << "\n";
    return 0;
}