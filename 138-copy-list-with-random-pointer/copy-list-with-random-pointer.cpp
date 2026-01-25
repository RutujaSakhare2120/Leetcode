/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //create dummpy nodes

        Node* dummy = new Node(50);   
        Node* curr = head;
        Node* aa = dummy;

        while (curr) {
            Node* node = new Node(curr->val);  
            aa->next = node;                    
            aa = aa->next;                        
            curr = curr->next;
        }

        Node* a=head;
        Node* b=dummy->next;

        //Make a map of <original,duplicate>


        unordered_map<Node* , Node*>m;
        Node* tempa=a;
        Node* tempb=b;
        while(tempa!=NULL){
            m[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }

        for(auto x:m){
            Node* o=x.first;
            Node* d=x.second;
            if(o->random!=NULL){
                Node* oRandom=o->random;
                Node* dRandom=m[o->random];
                d->random=dRandom;

            }

        }


        return b;

    }
};