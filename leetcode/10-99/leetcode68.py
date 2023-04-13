from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        cur_len = 0
        cur_str = []
        for word in words:
            if cur_len + len(word) <= maxWidth:
                cur_str.append(word)
                cur_len += len(word) + 1
            else:
                cur_len -= len(cur_str)
                if len(cur_str) == 1:
                    apnd = cur_str[0] + " " * (maxWidth - cur_len)
                else:
                    slot = len(cur_str) - 1
                    space_count = maxWidth - cur_len
                    r, q = divmod(space_count, slot)
                    apnd = cur_str[0]
                    if q == 0:
                        apnd = (" " * r).join(cur_str)
                    else:
                        for i in range(1, q + 1):
                            apnd += " " * (r + 1) + cur_str[i]
                        for i in range(q + 1, len(cur_str)):
                            apnd += " " * r + cur_str[i]
                res.append(apnd)
                cur_str = [word]
                cur_len = len(word) + 1

        if cur_len:
            cur_len -= len(cur_str)
            if len(cur_str) == 1:
                apnd = cur_str[0] + " " * (maxWidth - cur_len)
            else:
                slot = len(cur_str) - 1
                space_count = maxWidth - cur_len
                r, q = divmod(space_count, slot)
                apnd = cur_str[0]
                if q == 0:
                    apnd = (" " * r).join(cur_str)
                else:
                    for i in range(1, q + 1):
                        apnd += " " * (r + 1) + cur_str[i]
                    for i in range(q + 1, len(cur_str)):
                        apnd += " " * r + cur_str[i]
            res.append(apnd)
            cur_str = [word]
            cur_len = len(word) + 1

        last_str = res.pop()
        last_just = list(last_str.split())
        last_str = last_just[0]
        for i in range(1, len(last_just)):
            last_str += " " + last_just[i]
        while len(last_str) < maxWidth:
            last_str += " "
        res.append(last_str)
        return res


s = Solution()
s.fullJustify(
    words=["This", "is", "an", "example", "of", "text", "justification."], maxWidth=16
)
