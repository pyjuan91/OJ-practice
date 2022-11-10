#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        queue<int> neo;
        neo.push(x);
        while (!q.empty()) {
            neo.push(q.front());
            q.pop();
        }
        q = neo;
    }

    int pop()
    {
        int ret = q.front();
        q.pop();
        return ret;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main(void)
{
    return 0;
}