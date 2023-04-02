from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        if len(s) == 1:
            return [[s]]
        for i in range(len(s)):
            print(s[: i + 1], s[i::-1])
            if s[: i + 1] == s[i::-1]:
                print("yo")
                child = self.partition(s=s[i + 1 :])
                if len(child) == 0:
                    res.append([s[: i + 1]])
                else:
                    for c in child:
                        res.append([s[: i + 1]] + c)

        return res


s = Solution()
print(s.partition(s="aab"))
