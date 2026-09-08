# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # Iterate Till Right
        if left == right:
            return head
        i = 1
        root = head
        prev_node = root
        left_node = root
        while i < left:
            prev_node = root
            left_node = root.next
            root = left_node
            i = i + 1
        i = left
        while i < right:
            root = root.next
            i = i + 1
        # Get Next Node
        right_node_next = root.next
        root.next = None

        # Reverse List
        temp = ListNode(0)
        curr = left_node
        dummy = curr
        while(curr):
            next_node = curr.next
            curr.next = temp
            temp = curr
            curr = next_node
        dummy.next = right_node_next
        if left > 1:
            prev_node.next = temp
        if left > 1:
            return head
        else:
            return temp      