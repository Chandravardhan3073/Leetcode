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
    ListNode* AtHead(ListNode* &node,int val){
        ListNode* newNode = new ListNode(val);
        if(node== NULL){
            node = newNode;
        }else{
            newNode->next = node;
            node= newNode;
        }
        return node;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* l1 = reverse(head);
        ListNode* node = NULL;
        int sum = 0,digit = 0,carry = 0;
        while(l1){
            sum = l1->val * 2  + carry;
            digit = sum %10;
            carry = sum /10;
              AtHead(node,digit);
            l1 = l1->next;
        }
        if(carry){
           AtHead(node,carry);
        }
        return node;
    }
};