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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merge=new ListNode(-1);
       
        ListNode* tc=merge;


        ListNode* t1=list1;
        ListNode* t2=list2;

        while(t1!=NULL && t2!=NULL){
            if(t1->val>=t2->val){
                ListNode* helper=new ListNode(t2->val);
                tc->next=helper;
                t2=t2->next;

            }
            else{
                 ListNode* helper=new ListNode(t1->val);
                tc->next=helper;
                t1=t1->next;

            }
            tc=tc->next;
        }

        if(t1==NULL && t2!=NULL){
            tc->next=t2;
        }

        if(t1!=NULL && t2==NULL){
             tc->next=t1;
            
        }
        return merge->next; 
    }
};