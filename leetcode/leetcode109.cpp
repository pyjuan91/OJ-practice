#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        return Tzuyu(head, nullptr);
    }

private:
    TreeNode* Tzuyu(ListNode* left, ListNode* right)
    {
        if (left == right) {
            return nullptr;
        }
        if (left->next == right) {
            return new TreeNode(left->val);
        }
        ListNode *slow, *fast;
        slow = fast = left;
        while (fast && fast->next && fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* mid = new TreeNode(slow->val);
        mid->left = Tzuyu(left, slow);
        mid->right = Tzuyu(slow->next, right);
        return mid;
    }
};
int main(void) { return 0; }