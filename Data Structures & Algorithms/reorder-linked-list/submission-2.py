# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head.next is not None:
            # identify the 2 lists (using slow and fast pointers)
            # reverse the second list
            # reorder the list to get the final output

            # Identify 2 Lists
            slow = head
            fast = head.next

            while(fast and fast.next):
                slow = slow.next
                fast = fast.next.next
            second = slow.next
            slow.next = None

            # Reverse
            prev = ListNode(0)
            node = second
            next_node = second
            while(node):
                next_node = node.next
                node.next = prev
                prev = node
                node = next_node
            second.next = None
            
            #Reorder
            first = head
            second = prev
            temp_first = first
            temp_second = second

            while(first.next):
                temp_first = first.next
                first.next = second
                first = temp_first
                temp_second = second.next
                second.next = temp_first
                second = temp_second
            first.next = second
