# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None:
            return
        node = head
        nums = []
        while(node):
            nums.append(node.val)
            node = node.next

        i = 0
        j = len(nums) - 1
        counter = 0
        arranged_nums = [1 for i in range(len(nums))]

        while(counter < len(nums)):
            if(counter%2 == 0):
                arranged_nums[counter] = nums[i]
                i += 1
            elif(counter%2 != 0):
                arranged_nums[counter] = nums[j]
                j -= 1
            counter += 1
        
        for index in range(1, len(nums)):
            head.next.val = arranged_nums[index]
            head = head.next





