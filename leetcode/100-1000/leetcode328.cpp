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
        ListNode* oddHead = head;
        ListNode *evenHead = head->next, *evenPos = evenHead;
        while (evenPos && evenPos->next) {
            oddHead->next = evenPos->next;
            evenPos->next = evenPos->next->next;
            evenPos = evenPos->next;
            oddHead = oddHead->next;
        }
        oddHead->next = evenHead;
        return head;
    }
};
int main(void) { return 0; }