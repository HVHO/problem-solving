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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* res = head;
        ListNode* delay;
        
        
        
        for(int i = 0; i < n; i++) {
            res = res -> next;
        }
        
        if(!res) return head -> next;
        
        delay = head;
        
        while(res -> next) {
            delay = delay->next;
            res = res -> next;
        }
        
        delay -> next = delay -> next -> next;
        
        
        return head;
    }
};
