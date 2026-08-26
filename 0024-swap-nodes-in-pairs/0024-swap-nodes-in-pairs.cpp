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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL ||head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* prevTail = NULL;
        while(temp && temp->next){
            ListNode* nextPtr = temp->next;
            temp->next = nextPtr->next;
            nextPtr->next = temp;
            if(prevTail == NULL){
                head = nextPtr;
            }else{
                prevTail->next = nextPtr;
            }
            prevTail = temp;
            temp = temp->next;
        }
        return head;
    }
};