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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;//pointer traversal for the first LL
        ListNode* p2=l2;//pointer traversal for the second LL
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;//traversal pointer for the new LL
        int sum=0;
        while(p1 && p2){
            sum=p1->val+p2->val+carry;
            if(sum>=10){
                sum=sum%10;
                carry=1;
            }
            else carry=0;
            ListNode* temp=new ListNode(sum);
            cur->next=temp;
            cur=temp;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1){
            sum=carry+p1->val;
            if(sum>=10){
                carry=1;
                sum=sum%10;
            }
            else carry=0;
            ListNode* temp=new ListNode(sum);
            cur->next=temp;
            p1=p1->next;
            cur=cur->next;
        }

        while(p2){
            sum=carry+p2->val;
            if(sum>=10){
                carry=1;
                sum=sum%10;
            }
            else carry=0;
            ListNode* temp=new ListNode(sum);
            cur->next=temp;
            p2=p2->next;
            cur=cur->next;
        }

        if(carry){
            ListNode* temp=new ListNode(carry);
            cur->next=temp;
        }
        return dummy->next;
    }
};
