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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;  

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergeList(l1, l2);
    }
    
    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = p1;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->val <= head2->val) {
                p2->next = head1;
                head1 = head1->next;
            } else {
                p2->next = head2;
                head2 = head2->next;
            }
            p2 = p2->next;
        }
        
       
        if(head1 != NULL) {
            p2->next = head1;
        } else {
            p2->next = head2;
        }
        
        ListNode* result = p1->next;
        delete p1;
        return result;
    }
};