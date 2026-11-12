/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* currNode = dummyNode;
        int carryOver = 0;
        while(l1 || l2 || carryOver){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            int total = v1 + v2 + carryOver;
            int value = total%10;
            carryOver = total/10;

            ListNode* node = new ListNode(value);
            currNode->next = node;
            currNode = currNode->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummyNode->next;
    }
};
