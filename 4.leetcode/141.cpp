# 141. Linked List Cycle    

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *faster = head;
        ListNode *slower = head;
        
        int idx = 0;
        while(1) {
            if((++idx)%2) {
                faster = faster -> next;    
            } else {
                faster = faster -> next;
                slower = slower -> next;
                if(faster == slower) return true;
            }
            if(faster == nullptr || slower == nullptr) return false;
        }
        
        return false;
    }
};
