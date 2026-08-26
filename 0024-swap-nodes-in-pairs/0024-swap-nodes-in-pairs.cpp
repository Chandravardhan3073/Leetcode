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
        ListNode* temp = head;
        ListNode* prevTail ;
        int cnt = 1;
        if(head==NULL ||head->next == NULL){
            return head;
        }
        while(temp && temp->next){
            ListNode* Next = temp->next;
            temp->next = NULL;
            temp->next = Next->next;
            Next->next = NULL;
            Next->next = temp;

            if(cnt == 1){
                head = Next;
            }else{
                prevTail->next = Next;
            }
            cnt++;
            prevTail = temp;
            temp = temp->next;
        }
        return head;
    }
};