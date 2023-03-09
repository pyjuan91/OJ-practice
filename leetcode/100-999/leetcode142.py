# Definition for singly-linked list.
from typing import Optional
from collections import defaultdict


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return None
        slow = fast = head

        ans = head
        while True:
            if fast.next == None or fast.next.next == None:
                break
            fast = fast.next.next
            slow = slow.next

            if slow == fast:
                while ans != slow:
                    ans = ans.next
                    slow = slow.next

                return ans

        return None
