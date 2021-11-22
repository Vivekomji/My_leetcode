// https://leetcode.com/problems/intersection-of-two-linked-lists/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        if(A==NULL || B==NULL)  return NULL;
        while(A!=B){
            A=A==NULL?headB:A->next;
            B=B==NULL?headA:B->next;
        }
        return A;
    }
};