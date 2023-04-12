class Solution:
    def simplifyPath(self, path: str) -> str:
        p = []
        while path:
            path = self.eatSlash(path)
            if not path:
                break
            dirName = self.getDirName(path)
            if dirName == '..':
                if p:
                    p.pop()
            elif dirName == '.':
                pass
            else:
                p.append(dirName)
            path = path[len(dirName):]
        
        return "/" + "/".join(p)

    def getDirName(self, s:str) -> str:
        res = []
        for c in s:
            if c == '/':
                break
            res.append(c)
        return "".join(res)
    def eatSlash(self, s: str) -> str:
        for i in range(len(s)):
            if s[i] != '/':
                return s[i:]
        return ""
