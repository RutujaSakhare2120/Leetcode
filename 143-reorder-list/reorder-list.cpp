
class Solution {
public:
   ListNode* reverse(ListNode* head){
     ListNode* t=head;
     ListNode* newhead=NULL;

     while(head!=NULL){
        head=head->next;
        t->next=newhead;
        newhead=t;
        t=head;
     }

     return newhead;


   }
   ListNode* merge(ListNode* list1 , ListNode* list2){

     ListNode* a=list1;
     ListNode* b=list2;

     ListNode* newhead=new ListNode(100);
     ListNode* c=newhead;
     while(a!=NULL && b!=NULL){
        c->next=a;
        c=a;
        a=a->next;
        if(b!=NULL){
             c->next=b;
        c=b;
        b=b->next;

        }


     }
     if(a==NULL) c->next=b;
     else c->next=a;

     return newhead->next;


   }

    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* r=NULL;


        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        r=slow->next;
        slow->next=NULL;

        ListNode* newhead=reverse(r);
        head=merge(head , newhead);

        return;
        
    }
};