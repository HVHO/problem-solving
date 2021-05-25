// 	150. Evaluate Reverse Polish Notation    


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        
        for(auto token: tokens) {
            if(!token.compare("+")) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            } else if (!token.compare("-")) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            } else if (!token.compare("*")) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            } else if (!token.compare("/")) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            } else {
                s.push(atoi(token.c_str()));
            }
        }
        
        return s.top();
    }
};
