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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast= head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* cur=slow->next;
        slow->next=nullptr;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        ListNode* cur1=head;
        ListNode* cur2=prev;
        while(cur1 && cur2){
            ListNode* next1=cur1->next;
            ListNode* next2=cur2->next;
            
            cur1->next=cur2;
            cur2->next=next1;
            
            cur1=next1;
            cur2=next2;
        }
        
    }
};
