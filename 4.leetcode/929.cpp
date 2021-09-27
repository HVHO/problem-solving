// 929. Unique Email Address


class Solution {
public:
    
    string func(string email) {
        string res;
        int i;
        for(i = 0; i < email.length(); i++) {
            char c = email[i];
            if(c == '+') {
                while(email[i] != '@') i++;
                break;
            }
            if(c == '@') break;
            if(c != '.') {
                res += c;
            }
        }
        for(; i < email.length(); i++) {
            res += email[i];
        }
            
        return res;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;    
        for(auto email: emails) {
            s.insert(func(email));
        }
        return s.size();
    }
};
