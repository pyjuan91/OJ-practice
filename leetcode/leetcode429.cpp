#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() { }

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    vector<vector<int>> v;
    queue<Node*> q;
    queue<int> lv;

public:
    vector<vector<int>> levelOrder(Node* root)
    {
        if (root == nullptr)
            return v;
        q.push(root);
        lv.push(0);
        while (!q.empty()) {

            Node* cur = q.front();

            if (v.size() == lv.front())
                v.push_back(vector<int>());

            v[lv.front()].push_back(cur->val);

            for (auto i : cur->children) {
                q.push(i);
                lv.push(lv.front() + 1);
            }

            q.pop();
            lv.pop();
        }
        return v;
    }
};
int main(void) { return 0; }