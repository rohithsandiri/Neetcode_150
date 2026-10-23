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
    ListNode* rev(ListNode* head){
        if(!head)return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(head){
            head = head->next;
            temp -> next = prev;
            prev = temp;
            temp = head;
        }
        return prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return rev(head);
    }
};
