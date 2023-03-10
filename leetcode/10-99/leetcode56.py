from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = []
        if len(intervals) == 0:
            return res
        res.append(intervals[0])
        for i in intervals:
            if i[0] > res[-1][1]:
                res.append(i)
            elif i[1] > res[-1][1]:
                res[-1][1] = i[1]
        return res


s = Solution()
print(s.merge([[1,4],[4,5]]))

