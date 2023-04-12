class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = {}
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            if not dic.get(s[i]) and t[i] not in dic.values():
                dic[s[i]] = t[i]
            elif dic.get(s[i]):
                if t[i] != dic[s[i]]:
                    return False
            else:
                return False
        return True