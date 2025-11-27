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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        //step1 check if k nodes exist
        int cnt=0;
        
        while(cnt<k){
            if(temp==NULL) return head;
          temp = temp->next;
          cnt++;
        }

        //step 2 recursively call rest of ll
        ListNode* prevNode=reverseKGroup(temp , k);

        //step3 reverse current group
        temp=head;
        cnt=0;
        while(cnt<k){
            head=head->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=head;

            cnt++;
        }

        return prevNode;




        
    }
};