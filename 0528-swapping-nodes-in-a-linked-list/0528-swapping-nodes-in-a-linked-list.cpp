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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* slow=head;
        int count=1;
        
     while(count<k && slow->next!=NULL){
        slow=slow->next;
        count++;
     }
     ListNode* temp=slow;
     ListNode* fast=head;
     while(temp->next!=NULL){
        temp=temp->next;
        fast=fast->next;
     }

     swap(slow->val,fast->val);
     

    return head;
        
    }
};