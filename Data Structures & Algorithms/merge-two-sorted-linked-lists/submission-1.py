# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None and list2 is not None:
            return list2
        if list1 is not None and list2 is None:
            return list1
        if list1 is None and list2 is None:
            return 
        
        node1 = list1
        node2 = list2

        dummy_node = ListNode(-1)
        node = dummy_node

        while(node1 and node2):
            if(node2.val <= node1.val):
                node.next = node2
                node2 = node2.next
            elif(node1.val <= node2.val):
                node.next = node1
                node1 = node1.next
            node = node.next
        if(node1 is None):
            node.next = node2
        elif(node2 is None):
            node.next = node1
            
        return dummy_node.next

