class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        from collections import Counter

        n = len(secret)
        sec = Counter()
        gue = Counter()
        A = 0
        for i in range(n):
            if secret[i] == guess[i]:
                A += 1
            else:
                sec[secret[i]] += 1
                gue[guess[i]] += 1

        B = 0
        for i in range(10):
            B += min(sec[str(i)], gue[str(i)])

        return f"{A}A{B}B"
