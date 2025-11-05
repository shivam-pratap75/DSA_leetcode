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

            

                ListNode* temp1=head1;
                ListNode* temp2=head2;
                ListNode* sudo = NULL;
     if (head1->val < head2->val) {
     
        ListNode* temp = head1->next;
        head1->next = head2;
        head2 = head1;
        temp1 = temp;
        sudo = head2;
    } else {
        sudo = head2;
        temp2 = head2->next;
    }
        while(temp1 !=NULL && temp2 !=NULL){
            if(temp1->val <= temp2->val){
              ListNode* nextTemp1 = temp1->next;
            sudo->next = temp1;
            temp1->next = temp2;
            sudo = temp1;
            temp1 = nextTemp1;

            }else{
            sudo = temp2;
            temp2 = temp2->next;
            }
           


        }
         if(temp1!=NULL){
                sudo->next=temp1;

            }
        return head2;

       
    }
};