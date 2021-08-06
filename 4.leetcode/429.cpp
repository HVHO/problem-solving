// 429. N-ary Tree Level Order Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<Node *> q;
        q.push(root);

        while(int size = q.size()) {
            vector<int> tmp;
            while(size--) {
                auto cur = q.front();
                q.pop();
                tmp.push_back(cur->val);

                for(auto c: cur->children) {
                    q.push(c);
                }
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};
