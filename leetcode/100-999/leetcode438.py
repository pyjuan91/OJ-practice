from typing import List
from collections import Counter


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = []
        if len(s) < len(p):
            return res
        tar = Counter(p)
        cur = Counter(s[: len(p)])

        if tar == cur:
            res.append(0)
        front, back = 0, len(p)

        while back < len(s):
            cur[s[front]] -= 1
            cur[s[back]] += 1
            front += 1
            back += 1
            if tar == cur:
                res.append(front)

        return res


s = Solution()
print(s.findAnagrams(s="abab", p="ab"))
