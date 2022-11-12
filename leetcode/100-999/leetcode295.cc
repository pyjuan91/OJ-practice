#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder()
    {
        while (!left.empty()) {
            left.pop();
        }
        while (!right.empty()) {
            right.pop();
        }
    }

    void addNum(int num)
    {
        if (left.empty()) {
            left.push(num);
        } else if (right.empty()) {
            if (left.top() <= num) {
                right.push(num);
            } else {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        } else {
            if (num <= left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }

            while (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }

            while (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }
    }

    double findMedian()
    {
        if ((left.size() + right.size()) % 2 == 0) {
            return ((double)left.top() + (double)right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(void) { return 0; }