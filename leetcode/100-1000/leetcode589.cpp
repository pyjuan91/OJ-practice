#include <algorithm>
#include <iostream>
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
public:
    vector<int> preorder(Node* root)
    {
        vector<int> ans;
        anya(root, ans);
        return ans;
    }
    void anya(Node* root, vector<int>& ans)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        for (auto i : root->children) {
            anya(i, ans);
        }
        return;
    }
};
int main(void)
{
    return 0;
}