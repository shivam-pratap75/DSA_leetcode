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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)return head;
        ListNode* p1=head;
        ListNode* p2=head;
        int size=1;
        while(p2->next!=NULL){
            p2=p2->next; 
             size++;

        }
        k=k%size;
         if (k == 0) return head;
         for(int i = 0; i < size-k-1; i++) {
            p1 = p1->next;
        }

        ListNode* temp=p1->next;
        p1->next=NULL;
        p2->next=head;
        
        return temp;
        
    }
};