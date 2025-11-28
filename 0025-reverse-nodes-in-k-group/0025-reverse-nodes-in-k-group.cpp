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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL)  return NULL;

        ListNode* temp=head;
        int count=0;
        // check if there are k nodes or not 
        while(temp!=NULL && count<k){
            
            count++;
            temp=temp->next;

        }
        if(count<k) return head; // if there are less than k nodes return head


    ListNode* curr=head;
    ListNode* pre=NULL;
    ListNode* next_ptr=NULL;
    count=0;
    // reverse the k nodes of list 
        while(count<k && curr!=NULL){

            next_ptr=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next_ptr;
            count++;

        }
            // if next_ptr  is not null call the function again for next k nodes
        if(next_ptr!=NULL){
            ListNode* new_head=reverseKGroup(next_ptr,k);
            head->next=new_head;
        }
        return pre;
        
    }
};