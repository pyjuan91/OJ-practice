class WordDictionary:
    class Trie:
        def __init__(self) -> None:
            self.endOfWords = False
            self.child = [None] * 26

    def __init__(self):
        self.head = self.Trie()

    def addWord(self, word: str) -> None:
        pos = self.head
        for w in word:
            if not pos.child[ord(w) - ord("a")]:
                pos.child[ord(w) - ord("a")] = self.Trie()
            pos = pos.child[ord(w) - ord("a")]
        pos.endOfWords = True

    def search(self, word: str) -> bool:
        queue = [self.head]
        for w in word:
            if not queue:
                return False
            neo = []
            for q in queue:
                if w == '.':
                    for c in q.child:
                        if c:
                            neo.append(c)
                else:
                    if q.child[ord(w)-ord('a')]:
                        neo.append(q.child[ord(w)-ord('a')])
            queue = neo
        
        for q in queue:
            if q.endOfWords:
                return True
        return False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
wd = WordDictionary()
wd.addWord("b")
wd.addWord("ba")
print(wd.search("b"))

