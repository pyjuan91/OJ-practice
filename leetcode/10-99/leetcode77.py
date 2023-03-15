from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def chaewon(cur: List[int], p: int):
            if len(cur) == k:
                res.append(cur.copy())
                return
            for i in range(p, n + 1):
                cur.append(i)
                chaewon(cur=cur, p=i + 1)
                cur.pop()

        chaewon([], 1)
        return res


s = Solution()
print(s.combine(n=4, k=2))
