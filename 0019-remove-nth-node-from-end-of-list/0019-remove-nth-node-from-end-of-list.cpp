class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;

      
        while(fast != NULL && fast->next != NULL){
            count++;
            fast = fast->next->next;
            slow = slow->next;
        }

        int size;
        if(fast == NULL){
            size = count * 2;
        } else {
            size = count * 2 + 1;
        }

        
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int targetPos = size - n;  
        
        if(targetPos > count) {
            
            ListNode* current = slow;
           
            for(int i = count; i < targetPos - 1; i++) {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
           
            ListNode* current = head;
           
            for(int i = 0; i < targetPos - 1; i++) {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp;
        }

        return head;
    }
};