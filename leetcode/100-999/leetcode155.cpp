#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
class MinStack
{
private:
    stack<int> s;
    multiset<int> ms;

public:
    MinStack()
    {
        while (!s.empty())
            s.pop();
        if (!ms.empty())
            ms.clear();
    }

    void push(int val)
    {
        s.push(val);
        ms.insert(val);
    }

    void pop()
    {
        auto iter = ms.find(s.top());
        ms.erase(iter);
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return *(ms.begin());
    }
};
int main(void)
{
    MinStack ms;
    ms.push(0);
    ms.push(1);
    ms.push(0);
    cout << ms.getMin() << endl;
    cout << ms.top() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    return 0;
}
