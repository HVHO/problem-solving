// 299. Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int cow = 0, bull = 0;
        int size = secret.length();
        
        vector<bool> matched(size);
        vector<int> remain(10);
        
        for(int i = 0; i < size; i++) {
            if(secret[i] == guess[i]) {
              matched[i] = true;
                cow++;
            } 
            else remain[guess[i] - '0']++;
        }
        
        for(int i = 0; i < size; i++) {
            if(!matched[i]) {
                if(remain[secret[i] - '0'] > 0) {
                    bull++;
                    remain[secret[i] - '0']--;
                }
            }
        }
        
        char buf[10];
        sprintf(buf,"%dA%dB",cow, bull);
        return  string(buf);
        
    }
};