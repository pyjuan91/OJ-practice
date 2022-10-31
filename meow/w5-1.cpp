#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, num;
    cin >> n;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    while (n--) {
        cin >> num;
        if (left.empty()) {
            left.push(num);
        } else if (right.empty()) {
            if (num < left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);
            }
        } else {
            if (num < left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }

            while (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }

            while (left.size() < right.size()) {
                left.push(right.top());
                right.pop();
            }
        }
        cout << left.top();
        if (n)
            cout << " ";
    }
    cout << "\n";

    return 0;
}