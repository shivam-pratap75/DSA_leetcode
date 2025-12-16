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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n=lists.size();
        if(n==0) return NULL;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>> pq;

        for(auto temp :  lists){

            if(temp) pq.push({temp->val,temp});
        }

        ListNode* result =new ListNode(-1);
        ListNode* tail =result;

        while(!pq.empty()){
            auto [value,temp] =pq.top();
            pq.pop();
            tail->next=temp;
            tail=tail->next;

        if(temp->next!=NULL) pq.push({temp->next->val,temp->next});

        }
        return result->next;
        
    }
};