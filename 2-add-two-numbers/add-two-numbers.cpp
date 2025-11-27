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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* a=l1;
     ListNode* b=l2;
     ListNode* newList=new ListNode(50);
     ListNode* c=newList;
     int ans=0;
     int carry=0;

     while(a!=NULL && b!=NULL){
        int n=a->val + b->val+ carry;
        ans=n%10;
        carry=n/10;
        ListNode* newNode=new ListNode(ans);
        c->next=newNode;
        c=c->next;
         a=a->next;
        b=b->next;
        
     }

     if(a==NULL){
        while(b!=NULL){int n=b->val+carry;
        ans=n%10;
        carry=n/10;
        ListNode* newNode=new ListNode(ans);
        c->next=newNode;
        c=c->next;

       
        b=b->next;}
        

     }
     else{
        while(a!=NULL){
         int n=a->val+carry;
        ans=n%10;
        carry=n/10;
        ListNode* newNode=new ListNode(ans);
        c->next=newNode;
        c=c->next;
        a=a->next;}

     }
     if(carry>0){
        ListNode* newNode=new ListNode(carry);
        c->next=newNode;
     }


      return newList->next;
        
    }
};