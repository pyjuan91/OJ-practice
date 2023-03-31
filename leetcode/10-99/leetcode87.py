class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        if len(s1) == 1:
            return False

        this_condition = s1 + " " + s2

        try:
            if this_condition in self.map:
                return self.map[this_condition]
        except:
            self.map = {}

        for i in range(1, len(s1)):
            cond1 = self.isScramble(s1=s1[:i], s2=s2[:i]) and self.isScramble(
                s1=s1[i:], s2=s2[i:]
            )
            cond2 = self.isScramble(
                s1=s1[:i], s2=s2[len(s1) - i :]
            ) and self.isScramble(s1=s1[i:], s2=s2[: len(s1) - i])
            if cond1 or cond2:
                self.map[this_condition] = True
                return True

        self.map[this_condition] = False
        return False

