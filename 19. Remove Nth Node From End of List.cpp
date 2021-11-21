// https://leetcode.com/problems/remove-nth-node-from-end-of-list/



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)    return NULL;
        int count =0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            count ++;
        }
        if(n==count)    return head->next;
        int del = count - n-1;
        temp = head;
        while(del--){
            temp = temp->next;
        }
        ListNode* t = temp->next;
        temp->next = temp->next->next;
        delete t;
        return head;
    }
};