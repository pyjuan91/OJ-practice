#include <iostream>
using namespace std;
int main(void)
{
    long long n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        if (n % 10 < 5) {
            n /= 10;
        } else {
            n /= 10;
            n += 1;
        }
    }
    cout << n;
    if (n != 0) {
        for (int i = 0; i < k; i++)
            cout << 0;
    }
    cout << "\n";
    return 0;
}