# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return
        new_node = ListNode(-1)
        node = head
        while(node):
            temp = node.next
            node.next = new_node
            new_node = node
            node = temp
        head.next = None
        return new_node
