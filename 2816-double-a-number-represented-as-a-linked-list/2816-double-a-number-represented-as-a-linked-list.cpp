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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* curr = NULL;
        while(temp){
            curr = temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head  = reverse(head);
        ListNode* node = NULL;
        int sum = 0 ,carry = 0;
        ListNode* curr = head;
        while(curr){
            sum = curr->val * 2  + carry;
            curr->val = sum %10;
            carry = sum /10;
            curr = curr->next;
        }
        head = reverse(head);

        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};