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
class obj {
public:
    ListNode* node;
    int id;

    obj()
    {
        node = nullptr;
        id = 0;
    }

    obj(ListNode* node, int id)
    {
        this->node = node;
        this->id = id;
    }

    bool operator<(const obj& b) const
    {
        return node->val > b.node->val;
    }

    bool operator>(const obj& b) const
    {
        return node->val < b.node->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<obj> pq;
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr)
                continue;
            obj o(lists[i], i);
            lists[i] = lists[i]->next;
            pq.push(o);
        }

        ListNode *head = new ListNode(), *cur = head;
        while (!pq.empty()) {
            obj o = pq.top();
            pq.pop();
            cur->next = o.node;
            if (lists[o.id] != nullptr) {
                obj neo(lists[o.id], o.id);
                pq.push(neo);
                lists[o.id] = lists[o.id]->next;
            }
            cur = cur->next;
        }

        return head->next;
    }
};
int main(void) { return 0; }