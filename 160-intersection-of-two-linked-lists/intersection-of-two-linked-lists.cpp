/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=0;
        int sizeB=0;

        ListNode* tA=headA;
        ListNode* tB=headB;

        while(tA!=NULL){
            sizeA++;
            tA=tA->next;
        }
        while(tB!=NULL){
            sizeB++;
            tB=tB->next;
        }
        tA=headA;
        tB=headB;
        int n=abs(sizeA-sizeB);
        if(sizeA>sizeB){
            for(int i=1;i<=n;i++) tA=tA->next;
            while(tA != tB){
              tA=tA->next;
            tB=tB->next;
            }
        }
        else{
           for(int i=1;i<=n;i++) tB=tB->next;
           while(tA != tB){
              tA=tA->next;
            tB=tB->next;
            }
        }
       
         
        return tA;


        
    }
};