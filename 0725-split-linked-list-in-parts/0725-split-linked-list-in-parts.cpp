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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int size = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        
        vector<ListNode*> result;
        
        if (size < k) {
            ListNode* temp = head;
            while (temp != NULL) {
                result.push_back(temp);
                ListNode* next = temp->next;
                temp->next = NULL; 
                temp = next;
            }
            
            while (result.size() < k) {
                result.push_back(NULL);
            }
            return result;
        }
        
        int val = size / k;
        int top = size % k;
        ListNode* temp = head;
        
        while (top > 0) {
            int val1 = val + 1; 
            result.push_back(temp);
            
            
            for (int i = 0; i < val1 - 1; i++) {
                temp = temp->next;
            }
            
            
            ListNode* nextPart = temp->next;
            temp->next = NULL;
            temp = nextPart;
            
            top--;
            k--;
        }
        
        while (k > 0) {
            int val1 = val;
            result.push_back(temp);
            
            if (val1 > 0) {
                
                for (int i = 0; i < val1 - 1; i++) {
                    temp = temp->next;
                }
                
                
                ListNode* nextPart = temp->next;
                temp->next = NULL;
                temp = nextPart;
            }
            
            k--;
        }
        
        return result;
    }
};