#include <iostream>
#include <vector>
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

// class Solution {
// public:
//     Node* connect(Node* root)
//     {
//         if (root == nullptr)
//             return root;
//         if (root->left == nullptr && root->right == nullptr)
//             return root;
//         Node* left = connect(root->left);
//         Node* right = connect(root->right);
//         if (left)
//             left->next = right;
//         Node *lr = root->left, *rl = root->right;
//         while (lr && (lr->right || lr->left) && rl && (rl->left || rl->right)) {
//             if (lr->right) {
//                 if (rl->left) {
//                     lr->right->next = rl->left;
//                     rl = rl->left;
//                 } else {
//                     lr->right->next = rl->right;
//                     rl = rl->right;
//                 }
//                 lr = lr->right;
//             } else {
//                 if (rl->left) {
//                     lr->left->next = rl->left;
//                     rl = rl->left;
//                 } else {
//                     lr->left->next = rl->right;
//                     rl = rl->right;
//                 }
//                 lr = lr->left;
//             }
//         }
//         return root;
//     }
// };
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<vector<Node*>> v;

public:
    Node* connect(Node* root)
    {
        v.clear();
        helper(root, 0);
        int i, j;
        for (i = 0; i < v.size(); i++) {
            for (j = 0; j < v[i].size() - 1; j++) {
                v[i][j]->next = v[i][j + 1];
            }
        }
        return root;
    }
    void helper(Node* root, int depth)
    {
        if (root == nullptr)
            return;
        if (v.size() == depth) {
            vector<Node*> tmp;
            v.push_back(tmp);
        }
        v[depth].push_back(root);
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }
};

int main(void) { return 0; }