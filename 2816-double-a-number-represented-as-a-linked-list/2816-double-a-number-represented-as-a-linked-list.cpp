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

    ListNode* copyList(ListNode* head){
        ListNode* temp = head;
        
        ListNode* copyHead = NULL;
        ListNode* tail = NULL;
        while(temp){
            ListNode* newNode = new ListNode(temp->val);
            if(copyHead == NULL){
                copyHead = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            temp = temp->next;
        }
        return copyHead;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* l1 = reverse(head);

        ListNode* l2 = copyList(l1);

        ListNode* node = NULL;
        int sum = 0,digit = 0,carry = 0;
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            digit = sum %10;
            carry = sum /10;
              AtHead(node,digit);
            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry){
           AtHead(node,carry);
        }
        return node;
    }
};