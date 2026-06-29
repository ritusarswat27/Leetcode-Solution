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
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == NULL) return head;
        // vector<int> arr;
        // ListNode* node = head;
        // while(node != NULL) {
        //     arr.push_back(node->val);
        //     node = node->next;
        // }
        // sort(arr.begin() , arr.end());
        // node = head;
        // for(int num : arr) {
        //     node->val = num;
        //     node = node->next;
        // }
        // return head;  


        ListNode* temp = new ListNode(INT_MIN);
        temp->next = head;
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(curr->next->val >= curr->val) curr = curr->next;
            else{
                ListNode* node = curr->next;
                curr->next = node->next;
                ListNode* pre = temp;
                while(pre->next->val < node->val) pre = pre->next;
                node->next = pre->next;
                pre->next = node;
            }   
        }
        return temp->next;
    }
};