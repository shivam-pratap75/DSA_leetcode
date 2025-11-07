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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* p1=head;
        ListNode* p2=head->next;
        ListNode* sudo=p1;
        p1->next=p2->next;
        p2->next=p1;
        head=p2;
        ListNode* temp=p1;
        p1=p2;
        p2=temp;
        

        while(p2->next!=NULL ){
        if(p2->next!=NULL){
            p2=p2->next;
            p1=p1->next;
            if(p2->next!=NULL){
                p2=p2->next;
               p1=p1->next;

                 p1->next=p2->next;
               p2->next=p1;
               sudo->next=p2;
               sudo=p1;
                 ListNode* temp=p1;
                 p1=p2;
                 p2=temp;


            }else{
                return head;
            }
        }else{
            return head;
        }
        }
        return head;
    }
};