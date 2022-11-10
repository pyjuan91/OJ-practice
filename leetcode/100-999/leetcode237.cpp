#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        ListNode* toDelete = node->next;
        // *node = *node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete toDelete;
    }
};
int main(void)
{
    return 0;
}