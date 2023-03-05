from typing import List
from collections import defaultdict


class Solution:
    def minJumps(self, arr: List[int]) -> int:
        valPos = defaultdict(list)

        for pos, val in enumerate(arr):
            valPos[val].append(pos)

        distance = [None for i in range(len(arr))]
        queue = [0]
        distance[0] = 0
        
        while queue:
            cur = queue[0]
            dis = distance[cur]
            queue.pop(0)

            if cur > 0 and distance[cur - 1] == None:
                distance[cur - 1] = dis + 1
                queue.append(cur - 1)

            if cur < len(arr) - 1 and distance[cur + 1] == None:
                distance[cur + 1] = dis + 1
                queue.append(cur + 1)

            for pos in valPos[arr[cur]]:
                if distance[pos] == None:
                    distance[pos] = dis + 1
                    queue.append(pos)

            valPos[arr[cur]].clear()

        return distance[len(arr) - 1]


s = Solution()
print(s.minJumps([7, 7, 2, 1, 7, 7, 7, 3, 4, 1]))
