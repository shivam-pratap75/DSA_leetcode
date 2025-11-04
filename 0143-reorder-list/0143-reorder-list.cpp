class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL && temp->next->next != NULL) {
            ListNode* preserve = slow;
            
           
            while(preserve->next->next != NULL){
                preserve = preserve->next;
            }
            
            ListNode* lastNode = preserve->next;
            preserve->next = NULL;
            
            ListNode* nextTemp = temp->next;
            temp->next = lastNode;
            lastNode->next = nextTemp;

            temp = nextTemp;
        }
    }
};