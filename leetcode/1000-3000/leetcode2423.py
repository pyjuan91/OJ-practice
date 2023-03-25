from collections import Counter


class Solution:
    def equalFrequency(self, word: str) -> bool:
        counter = Counter()
        counter_counter = Counter()
        for w in word:
            counter[w] += 1
        for k, v in counter.items():
            counter_counter[v] += 1
        keys = list(counter_counter.keys())
        if len(keys) > 1:
            keys[0], keys[1] = max(keys[0], keys[1]), min(keys[0], keys[1])
        if (
            len(counter_counter) == 2
            and (
                (keys[0] - keys[1] == 1 and counter_counter[keys[0]] == 1)
                or (keys[1] == 1 and counter_counter[1] == 1)
            )
        ) or (
            len(counter_counter) == 1
            and (keys[0] == 1 or counter_counter[keys[0]] == 1)
        ):
            return True
        return False


s = Solution()
print(s.equalFrequency(word="abbcc"))
