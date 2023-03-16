from typing import List

import numpy as np


class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks = sorted(tasks, key=lambda x: x[1])
        open_time = set()
        for task in tasks:
            start_time, end_time, duration = task[0], task[1], task[2]
            for chosen in open_time:
                if duration == 0:
                    break
                if start_time <= chosen <= end_time:
                    duration -= 1
            for time in range(end_time, start_time - 1, -1):
                if duration == 0:
                    break
                if time in open_time:
                    continue
                open_time.add(time)
                duration -= 1
        return len(open_time)


s = Solution()
print(s.findMinimumTime([[1,3,2],[2,5,3],[5,6,2]]))

