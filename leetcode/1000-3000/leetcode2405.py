class Solution:
    def partitionString(self, s: str) -> int:
        res = index = 0
        while index < len(s):
            chaechae = 0
            res += 1
            while index < len(s):
                if chaechae & (1 << (ord(s[index]) - ord("a"))):
                    break
                chaechae |= 1 << (ord(s[index]) - ord("a"))
                index += 1
        return res

s = Solution()
print(s.partitionString(s = "abacaba"))
