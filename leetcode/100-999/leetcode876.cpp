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
    ListNode* middleNode(ListNode* head)
    {
        int sz = 0;
        ListNode* n = head;
        while (n != nullptr) {
            sz++;
            n = n->next;
        }
        n = head;
        sz /= 2;
        while (sz--) {
            n = n->next;
        }
        return n;
    }
};
int main(void)
{
    return 0;
}