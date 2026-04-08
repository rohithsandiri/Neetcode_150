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
    bool hasCycle(ListNode* head) {
        if(!head)return false;
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next && head->next->next)fast=head->next->next;
        else return false;
        while(fast && fast->next && fast->next->next){
            if(slow == fast)return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};
