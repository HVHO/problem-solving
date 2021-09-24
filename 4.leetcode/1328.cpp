// 1328. Break a Palindrome
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1) return "";
        
        bool flag = true;
        
        for(int i = 0; i < n/2; i++) {
            if(palindrome[i] != 'a') flag = false;
        }
        
        if(flag) {
            palindrome[n-1] = 'b';
        } else {
            int idx = 0;
            while(palindrome[idx]=='a') idx++;
            palindrome[idx] = 'a';
        }
        
        return palindrome;
    }
};
