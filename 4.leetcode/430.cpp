// 430. Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        stack<Node*> s;
        
        Node* prev = head;
        
        if(head->next) s.push(head->next);
        if(head->child) s.push(head->child);
        head -> child = nullptr;
        
        while(s.size()) {
            Node* c = s.top();
            s.pop();
            
            prev -> next = c;
            c -> prev = prev;
            
            if(c -> next) s.push(c -> next);
            if(c -> child) s.push(c -> child);
            c -> child = nullptr;
            prev = c;
        }

        return head;
    }
};
