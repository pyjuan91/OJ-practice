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
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode *oddHead = new ListNode(head->val), *oddPos = oddHead;
        ListNode *evenHead = new ListNode(head->next->val), *evenPos = evenHead;
        ListNode* pos = head->next;
        while (pos && pos->next) {
            oddPos->next = new ListNode(pos->next->val);
            if (pos->next->next)
                evenPos->next = new ListNode(pos->next->next->val);
            evenPos = evenPos->next;
            oddPos = oddPos->next;
            pos = pos->next->next;
        }
        oddPos->next = evenHead;
        return oddHead;
    }
};
int main(void) { return 0; }