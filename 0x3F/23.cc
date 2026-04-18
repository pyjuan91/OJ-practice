#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* lhs, ListNode* rhs) -> bool {
      return lhs->val > rhs->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
    for (ListNode* node : lists) {
      if (node != nullptr) pq.push(node);
    }
    ListNode* head = new ListNode;
    ListNode* cur = head;
    while (!pq.empty()) {
      cur->next = pq.top();
      pq.pop();
      cur = cur->next;
      if (cur->next != nullptr) pq.push(cur->next);
    }
    return head->next;
  }
};

int main() { return 0; }