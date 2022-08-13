#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void print_subset(int n, int s)
{
    for (int i = 0; i < n; i++) {
        if (s & (1 << i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        print_subset(n, i);
    }
    return 0;
}