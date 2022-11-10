#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> s;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stack<int> neo;
        stack<int> rev;
        neo.push(x);
        while (!s.empty()) {
            rev.push(s.top());
            s.pop();
        }
        while (!rev.empty()) {
            neo.push(rev.top());
            rev.pop();
        }
        s = neo;
    }

    int pop()
    {
        int ret = s.top();
        s.pop();
        return ret;
    }

    int peek()
    {
        return s.top();
    }

    bool empty()
    {
        return s.empty();
    }
};
int main(void)
{
    return 0;
}