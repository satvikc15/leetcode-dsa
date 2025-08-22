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
    void deleteNode(ListNode* node) {
        if(node==nullptr){
            return;
        }
        ListNode* prev=NULL;
        while(node->next){
            node->val=node->next->val;
            prev=node;
            node=node->next;
        }
        prev->next=NULL;
        delete node;


    }
};