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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int f = -1, p = -1, curr = 2, minVal = INT_MAX, maxVal = -1;
        vector<int> v(2, -1);
        ListNode* temp = head->next;
        ListNode* prev = head;
        while (temp->next != NULL) {
            if (prev->val > temp->val && temp->next->val > temp->val || prev->val < temp->val && temp->next->val < temp->val) {
                if(f == -1){
                    f = curr;
                    p = curr;
                }else{
                    minVal = min(curr - p,minVal);
                    maxVal = max(curr - f,maxVal);
                    p = curr;
                }
            }
            prev = temp;
            temp = temp->next;
            curr++;
        }
       
        if(minVal == INT_MAX){
            return v;
        }
        v[0] = minVal;
        v[1] = maxVal;
        return v;
    }
};