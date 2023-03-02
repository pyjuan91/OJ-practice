from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        while i < len(chars):
            j = i
            while j < len(chars) and chars[j] == chars[i]:
                j += 1

            nc = []
            if j - i > 1:
                dig = j - i
                while dig > 0:
                    nc.append(dig % 10)
                    dig //= 10
            
            while nc:
                i += 1
                chars[i] = str(nc[-1])
                nc.pop()

            i += 1
            while i < j:
                chars[i] = ' '
                i += 1
        
        i = 0
        j = 0
        n = len(chars)
        while i < n:
            if chars[i] != ' ':
                chars[j] = chars[i]
                j += 1
            i += 1
        
        chars = chars[:j]
        return len(chars)

s = Solution()
list = ["a","a","b","b","c","c","c"]
print(s.compress(list))
print(list)