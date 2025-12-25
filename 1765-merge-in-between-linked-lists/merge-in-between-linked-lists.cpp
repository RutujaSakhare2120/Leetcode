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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       ListNode* temp=list1;

       for(int i=1;i<a;i++){
         temp=temp->next;

       }

       ListNode* t2=temp;
       for(int i=0;i<=b-a+1;i++){
         t2=t2->next;

       }
       ListNode* tail=list2;
       while(tail->next!=NULL) tail=tail->next;

       temp->next=list2;
       tail->next=t2;

       return list1;



       



        
    }
};