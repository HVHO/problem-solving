// 148.	Sort List    

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
    ListNode* sortList(ListNode* head) {
        vector<int> ls;
        if(!head) return nullptr;
        while(head) {
            ls.push_back(head->val);
            head = head -> next;
        }
        sort(ls.begin(),ls.end());
        ListNode* res = new ListNode(0);
        ListNode* end = res;
        for(auto i: ls) {
            ListNode* tmp = new ListNode(i);
            end -> next = tmp;
            end = tmp;
        }
        
        return res -> next;
    }
};