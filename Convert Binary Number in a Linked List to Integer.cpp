// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/




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
    int getDecimalValue(ListNode* head) {
        long long n = 0;
        while(head){
            n = n*10 + head->val;
            head = head->next;
        }
        int ans = 0;
        int i=0;
        while(n){
            int last = n%10;
            ans += last * pow(2,i);
            i++;
            n = n/10;
        }
        return ans;
    }
};





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
    int getDecimalValue(ListNode* head) {
        string str = "";
        while(head){
            str += to_string(head->val);
            head = head->next;
        }
        int n = str.length();
        int i=0;
        int ans = 0;
        while(n--){
            ans += (str[i] - '0') * pow(2, n);
            i++;
        }
        return ans;
    }
};







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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        int ans = 0;
        while(len--){
            ans += (head->val * pow(2, len));
            head = head->next;
        }
        return ans;
    }
};





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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL){
            ans = ans*2 + head->val;
            head=head->next;
        }
        return ans;
    }
};