from collections import Counter


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = res = 0
        freq = Counter()
        for right in range(len(s)):
            freq[s[right]] += 1
            if right - left + 1 - max(freq.values()) <= k:
                res = max(res, right - left + 1)

            else:
                freq[s[left]] -= 1
                left += 1

        return res
    
s = Solution()
print(s.characterReplacement(s = "ABAB", k = 2))