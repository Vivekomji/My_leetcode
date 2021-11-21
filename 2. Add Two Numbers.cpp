// https://leetcode.com/problems/add-two-numbers/



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
        ListNode* l3 = new ListNode(0);
        if(l1 == NULL && l2 == NULL)    return NULL;
        if(l1 != NULL && l2 == NULL)    return l1;
        if(l1 == NULL && l2 != NULL)    return l2;
        int temp=0;
        ListNode* head = l3;
        while(l1 != NULL && l2 != NULL){
            temp += (l1->val + l2->val);
            ListNode* tt = new ListNode(temp%10);
            
            l3->next = tt;
            l3 = l3->next;
            
            temp /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            temp += l1->val;
            ListNode* tt = new ListNode(temp%10);
            
            l3->next = tt;
            l3 = l3->next;
            
            temp /= 10;
            l1 = l1->next;
            
        }
        while(l2){
            temp += l2->val;
            ListNode* tt = new ListNode(temp%10);
            
            l3->next = tt;
            l3 = l3->next;
            
            temp /= 10;
            l2 = l2->next;
            
        }
        if(temp){
            ListNode* tt = new ListNode(temp);
            
            l3->next = tt;
            l3 = l3->next;

        }
        return head->next;
    }
};