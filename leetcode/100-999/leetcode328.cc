#include <bits/stdc++.h>
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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        ListNode* cur = head->next->next;
        bool isOdd = true;
        while (cur) {
            if (isOdd) {
                odd->next = cur;
                odd = odd->next;
            } else {
                even->next = cur;
                even = even->next;
            }
            isOdd = !isOdd;
            cur = cur->next;
            odd->next = nullptr;
            even->next = nullptr;
        }
        odd->next = evenHead;
        return head;
    }
};
int main(void)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    head = s.oddEvenList(head);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
};
