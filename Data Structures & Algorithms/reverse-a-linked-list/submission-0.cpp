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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* fut=cur->next;
        while(fut){
            cur->next=prev;
            prev=cur;
            cur=fut;
            fut=fut->next;
        }
        cur->next=prev;
        head=cur;
        return head;
    }
};
