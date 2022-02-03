#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int main(void)
{
    multiset<int> ms;
    ms.insert(0);
    ms.insert(0);
    ms.insert(1);
    for(auto i: ms)
    cout << i << " ";
    cout << endl;
    cout<<ms.count(0) << endl;
    ms.erase(0);
    for(auto i: ms)
    cout << i << " ";
    cout << endl;
    return 0;
}