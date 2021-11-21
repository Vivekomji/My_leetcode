// https://leetcode.com/problems/merge-two-sorted-lists/



// Recursive approach:
 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        
        
    }
};


Iterative Approach:

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* nextl1 = l1;
        ListNode* nextl2 = l2;
        if(l1 == NULL && l2 == NULL)    return NULL;
        if(l1 == NULL && l2 != NULL)    return l2;
        if(l1 != NULL && l2 == NULL)    return l1;
        
        ListNode* head;
        if(l1->val <= l2->val){
            head = l1;
            nextl1 = l1->next;
        }else{
            head = l2;
            nextl2 = l2->next;
        }
        ListNode* temp = head;
        while(nextl1 != NULL && nextl2 != NULL){
            if(nextl1->val <= nextl2->val){
                head->next = nextl1;
                head = nextl1;
                nextl1 = nextl1->next;
                
                // l1->next = nextl2;
            }else{
                head->next = nextl2;
                head = nextl2;
                nextl2 = nextl2->next;
                // l2->next = nextl1
            }
        }
        if(nextl1 != NULL){
            head->next = nextl1;
        }else{
            head->next = nextl2;
        }
        return temp;
    }
};