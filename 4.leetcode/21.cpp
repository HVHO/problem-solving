// 21. Merge Two Sorted Lists    

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* thead = head;
        while(l1 || l2) {
            int next = 0;
            if(l1 && l2) {
                if(l1 -> val > l2 -> val) {
                    next = l2->val;
                    l2 = l2 -> next;
                } else {
                    next =l1->val;
                    l1 = l1 -> next;
                }
            } else if (l1) {
                next = l1->val;
                l1 = l1 -> next;
            } else {
                next = l2 -> val;
                l2 = l2 -> next;
            }
            
            thead -> next = new ListNode(next);
            thead = thead -> next;
        }
        return head -> next;
    }
};
