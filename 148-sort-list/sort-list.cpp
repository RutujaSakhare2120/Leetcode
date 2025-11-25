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
     ListNode* mergeSort(ListNode* list1, ListNode* list2) {

        ListNode* a=list1;
        ListNode* b=list2;
        ListNode* c=new ListNode(100);
        ListNode* t=c;

        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                t->next=a;
                a=a->next;
                t=t->next;

            }else{
                t->next=b;
                b=b->next;
                t=t->next;


            }
        }

        if(a==NULL && b!=NULL) {
            t->next=b;
                

        }
        if(b==NULL && a!=NULL){
            t->next=a;
               
        }


        return c->next;
    }
   
      
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next !=nullptr){
            slow=slow->next;
            fast=(fast->next)->next;
        }

        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;

        a=sortList(a);
        b=sortList(b);


        ListNode* c=mergeSort(a, b);
        return c;


        
    }
};