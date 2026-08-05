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
        elements = []

        while(list1):
            elements.append(list1.val)
            list1 = list1.next
        
        while(list2):
            elements.append(list2.val)
            list2 = list2.next
        
        elements.sort()

        temp = None

        for index in range(len(elements)):
            if(index == 0):
                head = ListNode(elements[index])
                head.next = None
            else:
                node = ListNode(elements[index])
                if(head.next is None):
                    head.next = node
                    temp = node
                else:
                    temp.next = node
                    temp = node
        return head
                    

        


        