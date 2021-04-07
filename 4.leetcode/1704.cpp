// 1704. Determine if String Halves Are Alike    

class Solution {
public:
    bool checkVowel(char c) {
        return c =='a' ||c=='e'||c=='i'||c=='o'||c=='u'||c =='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    
    bool halvesAreAlike(string s) {
        int a = 0;
        int b = 0;
        
        for(int i = 0; i < s.length()/2; i++)
        {
            if(checkVowel(s[i])) a++;
        }
        
        for(int i = s.length()/2; i < s.length(); i++)
        {
            if(checkVowel(s[i])) b++;
        }    
        
        return a ==b;
    }
};
