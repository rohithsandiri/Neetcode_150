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
        unordered_map<Node*, Node*>mp;
        Node* cur1=head;
        Node* dummy = new Node(0);
        Node* cur2=dummy;
        while(cur1){
            Node* temp=new Node(cur1->val);
            cur2->next=temp;
            cur2=temp;
            mp[cur1]=temp;
            cur1=cur1->next;
        }
        cur2->next=nullptr;

        cur1=head;
        cur2=dummy->next;
        while(cur1){
            Node* temp=mp[cur1->random];
            cur2->random=temp;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return dummy->next;
    }
};
