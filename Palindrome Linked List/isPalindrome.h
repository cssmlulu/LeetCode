/*
Given a singly linked list, determine if it is a palindrome.
*/


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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *fast,*slow;
        fast=head;slow=head;
        while(fast!=NULL&&fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow = slow->next;
        vector<int> vec;
        while(slow!=NULL) {
            vec.push_back(slow->val);
            slow=slow->next;
        }
        int i = vec.size()-1;
        while(i>=0) {
            if(vec[i]!=head->val) return false;
            i--;
            head=head->next;
        }
        return true;
    }
};



//Could you do it in O(n) time and O(1) space?
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};