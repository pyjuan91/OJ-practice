from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left = res = 0
        right = len(people) - 1
        while left <= right:
            if people[right] + people[left] <= limit:
                left += 1
            res += 1
            right -= 1
        return res
