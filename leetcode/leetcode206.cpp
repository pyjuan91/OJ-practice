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

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* ans = nullptr;
        while (head) {
            ans = new ListNode(head->val, ans);
            head = head->next;
        }
        return ans;
    }
};
int main(void)
{
    return 0;
}