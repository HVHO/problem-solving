// 13. Roman to Integer    

class Solution {
public:
    
    
    
    int romanToInt(string s) {
        int res = 0;
        
        map<char,int> m = {
            {'I', 0},
            {'V', 0},
            {'X', 0},
            {'L', 0},
            {'C', 0},
            {'D', 0},
            {'M', 0}
        };
        for(int i = s.length() - 1; i >= 0; i--) {
            switch(s[i]) {
                case 'I' : 
                    if(m['V'] != 0 || m['X'] != 0) {
                        res -= 1;
                    } else {
                        res += 1;
                    }
                    m['I']++;
                    break;
                case 'V' :
                    res += 5;
                    m['V']++;
                    break;
                case 'X' :
                    if(m['L'] != 0 || m['C'] != 0) {
                        res -= 10;   
                    } else {
                        res += 10;    
                    }
                    m['X']++;
                    break;
                case 'L' :
                    res += 50;
                    m['L']++;
                    break;
                case 'C' :
                    if(m['D'] != 0 || m['M'] != 0) {
                        res -= 100;
                    } else {
                        res += 100;
                    }
                    m['C']++;
                    break;
                case 'D' :
                    res += 500;
                    m['D'] ++;
                    break;
                case 'M' :
                    res += 1000;
                    m['M'] ++;
                    break;
                    
            }
        }
        
        return res;
    }
};
