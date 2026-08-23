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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* temp = node;
        while(temp){
            curr = temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL){
            slow = slow->next;
        }

        ListNode* newHead = reverse(slow);
        ListNode* t1 = head;
        ListNode* t2 = newHead;
        while(t2!= NULL){
            if(t1->val != t2->val){
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }
};