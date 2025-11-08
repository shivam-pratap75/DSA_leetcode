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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left == right) return head;

        int count = 1;

        ListNode* left_node = head;
        ListNode* right_node = head;

        
        if (left > 1) {
            
            for (int i = 1; i < left - 1; i++) left_node = left_node->next;

            
            for (int i = 1; i < right; i++) right_node = right_node->next;
        } else {
            
            for (int i = 1; i < right; i++) right_node = right_node->next;
        }

        
        ListNode* end = right_node->next;

     
        if (left == 1) {
            ListNode* curr = head;
            ListNode* prev = end;           
            ListNode* next;

            while (curr != end) {           
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            return prev;                    
        }

        
        ListNode* curr = left_node->next;   
        ListNode* prev = end;               
        ListNode* next;

        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        
        left_node->next = prev;
        return head;
    }
};
