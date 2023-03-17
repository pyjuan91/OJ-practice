class Trie:
    class TrieNode:
        def __init__(self) -> None:
            self.child = [None] * 26
            self.isEndOfWord = False

    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word: str) -> None:
        pos = self.root
        for c in word:
            index = ord(c) - ord("a")
            if pos.child[index] == None:
                pos.child[index] = self.TrieNode()
            pos = pos.child[index]
        pos.isEndOfWord = True

    def search(self, word: str) -> bool:
        pos = self.root
        for c in word:
            index = ord(c) - ord("a")
            if pos.child[index] == None:
                return False
            pos = pos.child[index]
        return pos.isEndOfWord

    def startsWith(self, prefix: str) -> bool:
        pos = self.root
        for c in prefix:
            index = ord(c) - ord("a")
            if pos.child[index] == None:
                return False
            pos = pos.child[index]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
