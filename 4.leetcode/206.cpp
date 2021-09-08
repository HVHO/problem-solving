// 206. Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        stack<ListNode*> s;
        while(head) {
            s.push(head);
            head = head -> next;
        }
        
        auto res = s.top();
        head = s.top();
        s.pop();
        while(s.size()) {
            head -> next = s.top();
            head = s.top();
            s.pop();
        }
        head -> next = nullptr;
        
        return res;
        
    }
};
