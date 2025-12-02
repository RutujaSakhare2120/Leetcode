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
    ListNode* mergeSort(ListNode* list1 , ListNode* list2){
        ListNode* a=list1 ;
        ListNode* b=list2;
        ListNode* newhead=new ListNode(20);
        ListNode* c=newhead;


        while(a!=NULL && b!=NULL){
            if(a->val > b->val){
                c->next=b;
                c=b;
                b=b->next;
            }
            else{
                c->next=a;
                c=a;
                a=a->next;
            }
        }
        if(a==NULL) c->next=b;
        else c->next=a;


        return newhead->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }

         ListNode* a=head;
        ListNode* b=nullptr;
         b=slow->next;
         slow->next=NULL;


         a=sortList(a);
         b=sortList(b);

         ListNode* c=mergeSort(a , b);

         return c;


        
        
    }
};