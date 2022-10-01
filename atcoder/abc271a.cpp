#include <bits/stdc++.h>
using namespace std;
char myBit[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << myBit[n / 16] << myBit[n % 16] << "\n";
    return 0;
}
