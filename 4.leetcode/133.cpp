
// 133.	Clone Graph    
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    vector<Node*> visit;
    
    Solution() {
        visit = vector<Node*>(101,nullptr);
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr) return nullptr;
        
        Node* c = new Node(node -> val, vector<Node*>());
        visit[node->val] = c;
        
        for(Node* n: node -> neighbors) {

            c -> neighbors.push_back(visit[n->val]!= nullptr? visit[n->val] : cloneGraph(n));    

        }
        return c;
    }
};