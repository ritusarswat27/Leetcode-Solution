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
        vector<int> ans;
        if(head->next == NULL || head->next->next == NULL) return {-1 , -1};
        ListNode* temp = head;
        int len = 2 , first = -1 , prev = -1 , minDist = INT_MAX , maxDist = -1;

        while(temp->next->next != NULL) {
            if((temp->next->val < temp->val && temp->next->val < temp->next->next->val) || (temp->next->val > temp->val && temp->next->val > temp->next->next->val)) {
                if(first ==  -1) {
                    first = len;
                    prev = len;
                }
                else {
                    minDist = min(minDist , len - prev);
                    maxDist = len - first;
                    prev = len;
                }
            }
            len++;
            temp = temp->next;
        }
        if(first == -1 || minDist == INT_MAX) return {-1, -1};
        return {minDist , maxDist};    
    }
};