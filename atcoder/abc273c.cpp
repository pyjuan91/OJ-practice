#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
    int n, e, num, last;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> e;
        pq.push(e);
    }
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            cout << "0\n";
        } else {
            num = 0;
            last = pq.top();
            while (!pq.empty()) {
                if (pq.top() == last) {
                    num++;
                    pq.pop();
                } else {
                    break;
                }
            }
            cout << num << "\n";
        }
    }
    return 0;
}