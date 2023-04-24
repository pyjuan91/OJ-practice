class Solution:
    def decodeString(self, s: str) -> str:
        res, cur = [], ""
        num = 0

        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                res.append(cur)
                res.append(num)
                cur = ""
                num = 0
            elif c == ']':
                num = res.pop()
                prev = res.pop() if res else ""
                cur = prev + cur * num
                num = 0
            else:
                cur += c
        
        return cur

s = Solution()
print(s.decodeString(s = "3[a]2[bc]"))