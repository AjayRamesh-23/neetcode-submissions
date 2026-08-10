# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return None
        
        length = 0
        curr = head
        while(curr):
            length += 1
            curr = curr.next
        
        if n > length:
            return None
        
        if n == length:
            return head.next

        position = length - n
        curr = head
        next_node = curr.next if curr.next else None

        i = 0
        while(i < position - 1 and curr.next):
            next_node = next_node.next
            curr = curr.next
            i = i + 1
        curr.next = next_node.next
        return head
