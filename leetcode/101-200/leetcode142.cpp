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
const int OVERANGE = 100005;
int pos;
class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode *fast, *slow, *ans;
        fast = slow = ans = head;
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                while (slow != ans) {
                    ans = ans->next;
                    slow = slow->next;
                }
                return ans;
            }
        }
        return nullptr;
    }
};
int main(void)
{
    return 0;
}