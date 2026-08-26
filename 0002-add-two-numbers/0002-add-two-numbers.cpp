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
        ListNode* curr = NULL;
        ListNode* temp = head;
        while(temp){
            curr = temp;
            temp  =temp->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }

    ListNode* AtTail(ListNode* &head,ListNode* &tail,int val){
        ListNode* newNode = new ListNode(val);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next= newNode;
            tail = newNode;
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL; 
        int carry = 0;
        int sum = 0;
        int digit = 0;
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
             digit = sum % 10;
            carry = sum / 10;
            
            AtTail(head,tail,digit);
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            sum = l1->val + carry;
            digit = sum%10;
            carry = sum / 10;
            AtTail(head,tail,digit);
            l1 = l1->next;
        }
        while(l2){
            sum = l2->val + carry;
            digit = sum%10;
            carry = sum / 10;
            AtTail(head,tail,digit);
            l2 = l2->next;
        }
        if(carry){
            AtTail(head,tail,carry);
        }
        return head;
    }
};