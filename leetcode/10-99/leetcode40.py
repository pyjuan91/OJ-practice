from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def chaewon(cur: List[int], pos: int, cs: int, lastPop: int):
            if cs > target:
                return
            if cs == target:
                res.append(cur.copy())
                return
            for i in range(pos+1, len(candidates)):
                if candidates[i] == lastPop:
                    continue
                cur.append(candidates[i])
                chaewon(cur, i, cs+candidates[i], lastPop=lastPop)
                lastPop = cur.pop()

        chaewon([], -1, 0, -1)
        return res


if __name__ == "__main__":
    candidates = [10,1,2,7,6,1,5]
    target = 8
    s = Solution()
    print(s.combinationSum2(candidates=candidates, target=target))
