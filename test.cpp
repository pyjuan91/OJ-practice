#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(void)
{
    map<int, set<int>> m;
    // m[1].insert(1);
    // m[1].insert(2);
    // m[1].insert(3);
    // m[1].insert(4);
    set<int>::iterator iter;
    iter = m[1].lower_bound(2);
    cout << (iter == m[1].end()) << endl;
    cout << *iter << endl;
    return 0;
}