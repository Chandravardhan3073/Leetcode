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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right){
            return head;
        }
        int cnt = 1;
        ListNode* temp = head;
        ListNode *st,*end,*rightSt;
        ListNode* leftEnd = NULL;
        
        while(temp){
            if(cnt == left-1){
                leftEnd = temp;
            }
            if(cnt == left){
                st = temp;
            }
            if(cnt == right){
                end = temp;
            }
            cnt++;
            temp = temp->next;
        }


        rightSt  = end->next;

        if(leftEnd != NULL){
            leftEnd->next = NULL; 
        }
        end->next = NULL;
 
        ListNode* newHead = reverse(st);
        
        if(leftEnd != NULL){
            leftEnd->next = newHead;
        }else{
            head = newHead;
        }

        st->next = rightSt;

        return head;
    }
};