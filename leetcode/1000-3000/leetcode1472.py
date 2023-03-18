class BrowserHistory:
    class WebNode:
        def __init__(self, url: str) -> None:
            self.url = url
            self.prev = None
            self.next = None

    def __init__(self, homepage: str):
        self.head = self.WebNode(url=homepage)
        self.cur = self.head

    def visit(self, url: str) -> None:
        self.cur.next = self.WebNode(url=url)
        self.cur.next.prev = self.cur
        self.cur = self.cur.next

    def back(self, steps: int) -> str:
        while steps and self.cur.prev:
            steps -= 1
            self.cur = self.cur.prev
        return self.cur.url

    def forward(self, steps: int) -> str:
        while steps and self.cur.next:
            steps -= 1
            self.cur = self.cur.next
        return self.cur.url


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
