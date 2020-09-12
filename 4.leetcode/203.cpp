//203. Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* idx = head;
        ListNode* res = new ListNode();
        ListNode* res1 = res;
        
        while(idx) {
            if(idx -> val != val) {
                res1 -> next = idx;
                res1 = idx;
            }

            idx = idx -> next;
        }
        res1->next = nullptr;        
        return res -> next;
    }
};