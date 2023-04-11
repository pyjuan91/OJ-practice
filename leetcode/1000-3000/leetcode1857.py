from typing import List
from collections import defaultdict


class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        route = [[] for _ in range(n)]
        indegree = [0] * n
        for edge in edges:
            route[edge[0]].append(edge[1])
            indegree[edge[1]] += 1
        path = []
        queue = [i for i in range(n) if indegree[i] == 0]
        chaewon = [[0] * 26 for _ in range(n)]
        for i in range(n):
            chaewon[i][ord(colors[i]) - ord("a")] += 1
        res = 0
        while queue:
            cur = queue.pop(0)
            path.append(cur)
            res = max(res, max(chaewon[cur]))
            for child in route[cur]:
                for i in range(26):
                    chaewon[child][i] = max(
                        chaewon[child][i],
                        chaewon[cur][i] + (ord(colors[child]) - ord("a") == i),
                    )
                indegree[child] -= 1
                if indegree[child] == 0:
                    queue.append(child)
        if len(path) != n:
            return -1

        return res
