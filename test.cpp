#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    priority_queue<int> pq;
    pq.push(2);
    pq.push(4);
    pq.push(1);
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}