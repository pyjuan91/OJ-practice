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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *fast, *slow, *last;
        fast = slow = head;
        while (n--) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            last = slow;
            slow = slow->next;
        }
        if (slow == head)
            head = head->next;
        else
            last->next = slow->next;
        return head;
    }
};
int main(void) { return 0; }