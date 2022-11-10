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
    ListNode* rotateRight(ListNode* head, int k)
    {
        ListNode *pos = head, *tail = head, *ans;
        int len = 0;
        while (pos != nullptr) {
            len++;
            tail = pos;
            pos = pos->next;
        }
        if (len == 1 || len == 0)
            return head;
        k %= len, len -= k - 1;
        
        pos = head;
        while (len--) {
            pos = pos->next;
        }
        tail->next = head;
        ans = pos->next;
        pos->next = nullptr;

        return ans;
    }
};
int main(void) { return 0; }