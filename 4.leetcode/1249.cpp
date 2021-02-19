// 1249. Minimum Remove to Make Valid Parentheses    

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int o_count = 0; // open  parentheses
        int c_count = 0; // close parentheses
        
        // foward dir
        string s1;
        for(char& c: s) {
            if(c == '(') {
                o_count++;
            } else if( c == ')') {
                c_count++;
                if(c_count > o_count) {
                    c_count--;
                    continue;
                }
            }
            s1 += c;
        }
        
        o_count = 0;
        c_count = 0;
        string s2;
        for(auto c = s1.rbegin(); c != s1.rend(); ++c) {
            if( *c == '(') {
                o_count++;
                if(o_count > c_count) {
                    o_count--;
                    continue;
                }
            } else if( *c == ')') {
                c_count++;
            }
            s2 += *c;
        }
        
        reverse(s2.begin(),s2.end());
        
        return s2;
    }
};
