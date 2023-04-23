from functools import lru_cache


class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        li = list(ord(s[i]) - ord("0") for i in range(len(s)))
        mod = int(1e9 + 7)

        @lru_cache
        def chaewon(head: int) -> int:
            if head == len(s):
                return 1
            if li[head] == 0:
                return 0
            res = 0
            for i in range(head, len(li)):
                cur = 0
                power = 0
                for j in range(i, head - 1, -1):
                    cur += li[j] * 10**power
                    power += 1
                if cur <= k:
                    res += chaewon(head=i + 1)
                    res %= mod
                else:
                    break
            return res

        return chaewon(0)


s = Solution()
print(s.numberOfArrays(s="1317", k=2000))
