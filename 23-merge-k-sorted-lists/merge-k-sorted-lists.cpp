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
    ListNode* merge(ListNode* list1 , ListNode* list2){
        //using S.C O(1);
        ListNode* a=list1;
        ListNode* b=list2;
        ListNode* c=new ListNode(100);
        ListNode* t=c;

        while(a!=NULL && b!=NULL){
            if(a->val>=b->val){
                t->next=b;
                b=b->next;
                t=t->next;
            }
            else{
                t->next=a;
                a=a->next;
                t=t->next;

            }
        }

        if(a== NULL) t->next=b;
        else if(b==NULL) t->next=a;

        return c->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        if(n==0) return NULL;
        

        while(n>1){

            //last ele
            ListNode* a=lists[0];
            lists.erase(lists.begin());

            //Second last ele
            ListNode* b=lists[0];
            lists.erase(lists.begin());

            ListNode* c=merge(a , b);
            lists.push_back(c);
            n--;


        }

        return lists[0];
    }
};