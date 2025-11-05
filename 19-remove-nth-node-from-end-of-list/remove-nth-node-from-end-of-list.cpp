
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        
        while(temp !=NULL){
            size++;
            temp=temp->next;
        }
       
       if(n==size) {head=head->next; return head;}

        temp=head;
        // if(1 == (size-n)+1) head=head->next;

       for(int i=1;i<=size-n-1;i++){
         temp=temp->next;
       }
        temp->next = temp->next->next;
       
       

       return head;
    }
};