class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {   if(head==NULL) return 0;
     ListNode* t=head;
     int size=0;
     while(t->next!=NULL){
         size++;
         t=t->next;
     }
     if(size+1<=k){
        k=k%(size+1);
     }
     int idx=size-k;
     ListNode* tail=t;
     t=head;

     for(int i=1;i<=idx;i++){
        t=t->next;
     }

     tail->next=head;
     head=t->next;
     t->next=NULL;



    return head;

     




     return t;


    

        
    }
};