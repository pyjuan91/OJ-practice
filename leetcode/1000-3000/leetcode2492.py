from typing import List


class DisjointSet:
    def __init__(self, n: int) -> None:
        self.n = n
        self.parent = [i for i in range(n + 1)]
        self.cost = [int(1e5)] * (n + 1)

    def findRoot(self, a: int) -> int:
        self.cost[a] = min(self.cost[self.parent[a]], self.cost[a])
        self.cost[self.parent[a]] = self.cost[a]
        if self.parent[a] == a:
            return a
        self.parent[a] = self.findRoot(self.parent[a])
        return self.parent[a]

    def isSame(self, a: int, b: int) -> bool:
        return self.findRoot(a) == self.findRoot(b)

    def unite(self, a: int, b: int, dis: int) -> None:
        self.parent[self.findRoot(b)] = self.findRoot(a)
        self.cost[a] = min(self.cost[a], dis)
        self.cost[b] = min(self.cost[b], dis)


class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        djs = DisjointSet(n)
        for road in roads:
            djs.unite(road[0], road[1], road[2])
        for i in range(2, n + 1):
            djs.isSame(i, 1)
        return djs.cost[1]
