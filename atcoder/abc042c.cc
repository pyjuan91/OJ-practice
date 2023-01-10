#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool check(int n, vector<int>& num)
{
    while (n) {
        if (num[n % 10]) {
            n /= 10;
            continue;
        }
        return false;
    }
    return true;
}
int main(void)
{
    int n, k, x;
    cin >> n >> k;
    vector<int> num(10, 1);
    for (int i = 0; i < k; i++) {
        cin >> x;
        num[x] = 0;
    }
    for (; !check(n, num); n++);
    cout << n;
    return 0;
}