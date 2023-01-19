#include <algorithm>
#include <iostream>
using namespace std;
int main(void)
{
    int a, b;
    cin >> a >> b;
    cout << ((b == a * 2 || b == a * 2 + 1) ? "Yes" : "No");
    return 0;
}