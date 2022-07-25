#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int a, b, N;
    vector<int> deci;
    while (cin >> a >> b >> N) {
        deci.clear();
        cout << a / b << ".";
        a %= b;
        while (N--) {
            a *= 10;
            deci.push_back(a / b);
            a %= b;
        }
        for (auto i : deci) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}