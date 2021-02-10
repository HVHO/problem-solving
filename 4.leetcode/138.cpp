// 138. Copy List with Random Pointer    

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m;
        
        Node* res = new Node(0);
        Node* thead = head;
        Node* rhead = res;
        while(thead) {
            rhead -> next = new Node(thead -> val);
            m[thead] = rhead -> next;
            thead = thead -> next;
            rhead = rhead -> next;
        }
        
        rhead = res -> next;
        thead = head;
        while(thead) {
            rhead -> random = m[thead -> random];
            thead = thead -> next;
            rhead = rhead -> next;
        }
        
        return res -> next;
    }
};
