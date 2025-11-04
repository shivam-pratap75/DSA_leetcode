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

        ListNode* temp = slow;
        vector<ListNode*> value;
        while(temp != NULL && temp->next != NULL){
            value.push_back(temp->next);
            temp = temp->next;
        }

        ListNode* nexttemp = head;
        int n = value.size() - 1;

        while(nexttemp != slow && n >= 0){
            ListNode* val = nexttemp->next;
            nexttemp->next = value[n];
            value[n]->next = val;
            nexttemp = val;
            n--;
        }
        slow->next = NULL; 
    }
};