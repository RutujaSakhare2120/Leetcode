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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>v;
        ListNode* temp=head;
        while(temp){
            int node=temp->val;
            v.push_back(node);
            temp=temp->next;
        }
        int n=v.size();
        int i=k-1;int j=n-k;
       
        swap(v[i] , v[j]);

        
       ListNode* newhead=new ListNode(50);
       ListNode* c=newhead;
       for(int i=0;i<v.size();i++){
         int node=v[i];
         ListNode* node1=new ListNode(node);
         c->next=node1;
         c=node1;
         
       }
       return newhead->next;
        
    }
};