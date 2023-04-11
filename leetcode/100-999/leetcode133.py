# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        if not node:
            return None
        queue = [node]
        dic = {node: Node(val=node.val)}
        while queue:
            cur = queue.pop(0)
            for neighbor in cur.neighbors:
                if not dic.get(neighbor):
                    dic[neighbor] = Node(val=neighbor.val)
                    queue.append(neighbor)
        vist = set()
        queue.append(node)
        while queue:
            cur = queue.pop(0)
            vist.add(cur)
            dic[cur].neighbors = [dic[neighbor] for neighbor in cur.neighbors]
            for neighbor in cur.neighbors:
                if neighbor not in vist:
                    queue.append(neighbor)
        return dic[node]
