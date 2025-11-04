
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
    
        }

        int n=size/2 ;
        temp=head;
       for(int i=1;i<=n;i++){
            temp=temp->next;
    
     }
     return temp;

    }
};