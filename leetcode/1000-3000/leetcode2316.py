from typing import List


class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        e = [[] for _ in range(n)]
        vist = [False] * n
        res = pre = 0
        for edge in edges:
            a, b = edge[0], edge[1]
            e[a].append(b)
            e[b].append(a)
        def chaewon(cur: int)->int:
            child = 0
            for c in e[cur]:
                if not vist[c]:
                    vist[c] = True
                    child += chaewon(c)
            return child + 1
        for i in range(n):
            if not vist[i]:
                vist[i] = True
                CC = chaewon(i)
                res += CC * pre
                pre += CC
        return res