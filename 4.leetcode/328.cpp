// 328. Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* h1 = new ListNode();
        ListNode* h2 = new ListNode();
        
        ListNode* th1 = h1;
        ListNode* th2 = h2;
        
        int idx = 0;
        while(head) {
            if(idx&1) {
                th2 -> next = head;
                th2 = head;
            } else {
                th1 -> next = head;
                th1 = head;
            }
            head = head -> next;
            idx++;
        }
        th2 -> next = nullptr;
        th1 -> next = h2 -> next;
        
        return h1 -> next;
    }
};
