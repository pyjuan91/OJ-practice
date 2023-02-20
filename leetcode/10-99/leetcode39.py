from typing import List


class Solution:
    def combinationSum(self, candidates: List[int],
                       target: int) -> List[List[int]]:
        res = []
        def go(cur: List[int], pos: int):
            if sum(cur) > target:
                return
            if sum(cur) == target:
                res.append(cur.copy())
                return
            for i in range(pos, len(candidates)):
                cur.append(candidates[i])
                go(cur=cur, pos=i)
                cur.pop()
        
        go([], 0)
        return res

if __name__ == "__main__":
    candidates = [2,3,6,7]
    target = 7
    s = Solution()
    print(s.combinationSum(candidates=candidates, target=target))
