#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v(10);
    v[1] = 9, v[4] = 4;
    for (int& i : v) {
        cout << i << " ";
    }
    cout << endl;
    v.resize(15);
    for (int& i : v) {
        cout << i << " ";
    }
    cout << endl;
    v.resize(4);
    for (int& i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}