from typing import List


class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        time_vist_node = [0] * len(edges)
        cur_time = 1
        res = -1
        for i in range(len(edges)):
            if time_vist_node[i] == 0:
                start_time = cur_time
                cur_node = i
                while cur_node != -1 and time_vist_node[cur_node] == 0:
                    time_vist_node[cur_node] = cur_time
                    cur_time += 1
                    cur_node = edges[cur_node]
                if cur_node != -1 and time_vist_node[cur_node] >= start_time:
                    res = max(res, cur_time - time_vist_node[cur_node])
        return res
