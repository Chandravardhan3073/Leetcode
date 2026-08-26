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
    ListNode* AtHead(ListNode* &head,int val){
        ListNode* newNode = new ListNode(val);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* t1 = reverse(l1);
        ListNode* t2 = reverse(l2);
        
        int carry = 0;
        int digit = 0;
        int sum = 0;
        while(t1 && t2){
            sum = t1->val + t2->val+carry;
            digit = sum % 10;
            carry = sum /10;

            AtHead(head,digit);
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
            sum = t1->val + carry;
            digit = sum % 10;
            carry = sum /10;

            AtHead(head,digit);
            t1 = t1->next;
        }
        while(t2){
            sum = t2->val + carry;
            digit = sum % 10;
            carry = sum /10;

            AtHead(head,digit);
            t2 = t2->next;
        } 
        if(carry){
            AtHead(head,carry);
        }

        return head;
    }
};