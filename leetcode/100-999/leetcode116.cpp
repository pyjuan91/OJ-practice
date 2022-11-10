#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    Node(int _val)
        : val(_val)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {
    }
};

class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == nullptr)
            return root;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        Node* left = connect(root->left);
        Node* right = connect(root->right);
        left->next = right;
        Node *lr = root->left, *rl = root->right;
        while (lr->right && rl->left) {
            lr->right->next = rl->left;
            lr = lr->right;
            rl = rl->left;
        }
        return root;
    }
};
int main(void) { return 0; }