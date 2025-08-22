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
     ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) return true;
        ListNode* mid;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        mid = rev(slow);
        while(mid!=NULL){
            if(head->val==mid->val){
                head=head->next;
                mid=mid->next;
            }else{
                return false;
            }
        }
        return true;
    }
};