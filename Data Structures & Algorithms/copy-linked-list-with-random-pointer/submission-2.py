"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

import copy

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        node = head
        hashmap = {}
        index = 0
        while(node):
            hashmap[node] = Node(node.val)
            node = node.next
        node = head

        while(node):
            newnode = hashmap.get(node)
            newnode.next = hashmap.get(node.next)
            newnode.random = hashmap.get(node.random)
            node = node.next
        
        return hashmap.get(head)
