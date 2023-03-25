from typing import List


class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        inner_edge = [[] for _ in range(n)]
        outter_edge = [[] for _ in range(n)]
        for connection in connections:
            a, b = connection[0], connection[1]
            inner_edge[b].append(a)
            outter_edge[a].append(b)
        q = [0]
        vist = [True] + [False] * n
        res = 0
        while q:
            for e in inner_edge[q[0]]:
                if not vist[e]:
                    vist[e] = True
                    q.append(e)
            for e in outter_edge[q[0]]:
                if not vist[e]:
                    res += 1
                    vist[e] = True
                    q.append(e)
            q.pop(0)
        return res


s = Solution()
print(s.minReorder(n=6, connections=[[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]]))
