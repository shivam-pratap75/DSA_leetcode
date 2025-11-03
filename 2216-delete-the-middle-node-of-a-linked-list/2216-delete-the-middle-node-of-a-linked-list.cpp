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
    ListNode* deleteMiddle(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;


        while(fast != NULL && fast->next != NULL){
           fast=fast->next->next;

           if(fast != NULL && fast->next != NULL){
            slow=slow->next;
           }
      
        }

        ListNode* todelete=slow->next;
        slow->next=todelete->next;
        todelete->next=NULL;
        delete todelete;

        return head;
        
    }
};