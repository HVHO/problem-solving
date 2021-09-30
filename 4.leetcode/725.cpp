// 725. Split Linked List in Parts


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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto thead = head;
        while(thead) {
            n++;
            thead = thead -> next;
        }
        vector<ListNode*> res;
        for(int i = 0; i < k; i++) {
            int size = n/k + (i < n%k ? 1 : 0);
            res.push_back(head);
            for(int j = 0; j < size - 1; j++)
                head = head -> next;
            if(head) {
                auto thead = head;
                head = head -> next;
                thead -> next = nullptr;
            }
        }
        
        return res;
    }
};
