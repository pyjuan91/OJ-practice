#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

class NestedIterator {
private:
    queue<int> q;

public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++) {
            helper(nestedList[i]);
        }
    }

    void helper(NestedInteger& ni)
    {
        if (ni.isInteger()) {
            q.push(ni.getInteger());
            return;
        }
        vector<NestedInteger> list = ni.getList();
        for (int i = 0; i < list.size(); i++) {
            helper(list[i]);
        }
    }

    int next()
    {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext()
    {
        return q.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main(void) { return 0; }