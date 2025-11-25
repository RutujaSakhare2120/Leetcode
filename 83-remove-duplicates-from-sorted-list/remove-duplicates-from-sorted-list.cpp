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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* t=head;
        ListNode* p=head->next;

       while(p!=nullptr){
         while(p!=nullptr && p->val==t->val){
            p=p->next;

        }
        t->next=p;
        t=p;
       if(p!=nullptr) p=p->next;
       }
       

        return head;
    }
};