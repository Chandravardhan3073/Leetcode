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
        if(left == 1){
            int cnt = 1;
            ListNode* e , *t,*rightSt,*temp;
            temp = head;
            while(temp){
                cnt++;
                if(cnt == right){
                    t = temp;
                }
                temp = temp->next;
            }
            e = t->next;
            rightSt = e->next;

            e->next = NULL;
            ListNode* newHead = reverse(head);

            head->next = rightSt;
            return newHead;
        }

        int cnt = 1;
        ListNode* temp = head;
        ListNode* leftEnd,*st,*end,*rightSt,*t;
        while(temp){
            cnt++;
            if(cnt == left){
                leftEnd = temp;
            }
            if(cnt == right){
                t = temp;
            }
            temp = temp->next;
        }
         
        st = leftEnd->next;
        end =  t->next;
        rightSt = end->next;
        
        leftEnd->next = NULL;
        end->next = NULL;

        ListNode* newHead = reverse(st);


        leftEnd->next = newHead;
        st->next = rightSt;

        return head;
    }
};