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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
       // k=k%mod;
        ListNode* fin = nullptr;
        if(k==0 || head==NULL) return head;
        while(temp){
            n++;
            if(temp->next==NULL) fin=temp;
            temp=temp->next;
            
        }
        k=k%n;
        if(k==0) return head;
        temp=head;
        ListNode* prev=NULL;
        for(int i=0;i<n-k-1;i++){
            prev=temp;
            temp=temp->next;
        }
        ListNode* temp2=temp->next;
        if(temp==fin) {
            prev->next=NULL;
            temp2=fin;
        } 
        temp->next=nullptr;
        fin->next=head;
        return temp2;
    }
};