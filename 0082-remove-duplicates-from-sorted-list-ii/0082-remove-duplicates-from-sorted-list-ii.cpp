class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* p1 = NULL;
        ListNode* p2 = head;
        
       
        while (p2 != NULL && p2->next != NULL && p2->val == p2->next->val) {
            int duplicateVal = p2->val;
            while (p2 != NULL && p2->val == duplicateVal) {
                p2 = p2->next;
            }
            head = p2;
        }
        
        if (head == NULL || head->next == NULL) return head;
        
        p1 = head;
        p2 = head->next;
        
        while (p2 != NULL) {
            if (p2->next != NULL && p2->val == p2->next->val) {
               
                int duplicateVal = p2->val;
                while (p2 != NULL && p2->val == duplicateVal) {
                    p2 = p2->next;
                }
               
                p1->next = p2;
            } else {
               
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return head;
    }
};