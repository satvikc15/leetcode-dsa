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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==nullptr) return nullptr;
        while(fast!=NULL && fast->next!=NULL && slow!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};