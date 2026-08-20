# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if l1 is None and l2 is None:
            return None
        dummy_node = ListNode(0)
        curr = dummy_node
        carry_over = 0
        total = 0
        while l1 or l2 or carry_over:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            total = val1 + val2 + carry_over
            value = total%10
            carry_over = total//10
    
            curr.next = ListNode(value)
            curr = curr.next

            l1 = l1.next if l1 is not None else None
            l2 = l2.next if l2 is not None else None
        return dummy_node.next

        

        