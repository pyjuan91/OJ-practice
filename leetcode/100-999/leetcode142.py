# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        slow = fast = ans = head
        while True:
            if not fast.next or not fast.next.next:
                return None
            fast = fast.next.next
            slow = slow.next

            if slow == fast:
                while ans != slow:
                    ans = ans.next
                    slow = slow.next
                break
        
        return slow
        