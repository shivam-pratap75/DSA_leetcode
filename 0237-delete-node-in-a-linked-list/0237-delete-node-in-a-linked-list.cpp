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

            ListNode* temp=node;
        while(node->next!=NULL){
            
            temp->val=node->next->val;
            node=node->next;
            if(node->next!=NULL){
                temp=temp->next;
            }
            

        }
        temp->next=NULL;
        
    }
};