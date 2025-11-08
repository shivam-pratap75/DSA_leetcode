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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* greater;
        ListNode* temp;
        ListNode* temp1;
        ListNode* curr = head;
        
        if(curr->val >= x) {
          
            greater = head;
            temp1 = head;
            ListNode* prev = NULL;
            
            while(curr != NULL && curr->val >= x) {
                temp1 = curr;      
                prev = curr;
                curr = curr->next;
            }
            
            if(curr == NULL) return head;  
            
            head = curr;  
            temp = curr;  
            curr = curr->next;  
            
        } else {
           
            temp = head;
            ListNode* prev = NULL;
            
            while(curr != NULL && curr->val < x) {
                temp = curr;      
                prev = curr;
                curr = curr->next;
            }
            
            if(curr == NULL) return head;  
            
            greater = curr;  
            temp1 = curr;    
            curr = curr->next;  
        }
        
        
        while(curr != NULL) {
            if(curr->val >= x) {
                temp1->next = curr;
                temp1 = temp1->next;
            } else {
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
        }
        
        temp->next = greater;
        temp1->next = NULL;
        
        return head;
    }
};