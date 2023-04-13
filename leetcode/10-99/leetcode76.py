from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        rec = Counter(t)
        i, start, end = 0, -(10**6), 10**6
        missing = len(t)
        for j, c in enumerate(s):
            if rec[c] > 0:
                missing -= 1
            rec[c] -= 1
            if missing == 0:
                while i < j and rec[s[i]] < 0:
                    rec[s[i]] += 1
                    i += 1
                if j - i < end - start:
                    start, end = i, j

                missing += 1
                rec[s[i]] += 1
                i += 1
        return s[start : end + 1] if start >= 0 else ""
