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
private:
    void solve(ListNode* node, ListNode* list1, ListNode* list2){
        if(!list1){
            node -> next = list2;
            return ;
        }
        if(!list2){
            node -> next = list1;
            return;
        }
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* cur = node;
        while(first && second){
            if(first -> val <= second -> val){
                cur -> next = first;
                first = first -> next;
                cur = cur -> next;
            }
            else if(first -> val > second -> val ){
                cur -> next = second;
                second = second -> next;
                cur = cur -> next;
            }
        }
        if(first){
            cur -> next = first;
        }
        else if(second){
            cur -> next = second;
        }
        return;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *node = new ListNode(0);
        solve(node,list1, list2);
        return node->next;
    }
};
