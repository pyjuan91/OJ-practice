class Solution:
    def isNumber(self, s: str) -> bool:
        pos_neg = False
        dici = False
        nu = False
        sci = False
        if len(s) == 0:
            return False
        if s[0] == '+' or s[0] == '-':
            pos_neg = True
        elif s[0] == '.':
            dici = True
        elif str.isdigit(s[0]):
            nu = True
        else:
            return False
        for i in range(1, len(s)):
            if str.isdigit(s[i]):
                nu = True
            elif s[i] == '.' and dici == False:
                dici = True
            elif (s[i] == 'e' or s[i] == 'E') and nu and not sci:
                sci = True
                dici = True
                nu = False
            elif (s[i] == '+' or s[i] == '-') and (s[i-1] == 'e' or s[i-1] == 'E'):
                pass
            else:
                return False
        return nu 