// 1286. Iterator for Combination

class CombinationIterator {
public:
    
    set<string> s;
    set<string>::iterator si;
    
    CombinationIterator(string characters, int combinationLength) {
    
        unsigned int len = characters.size();
        
        for(unsigned int mask = 0; mask < (1 << len); mask++) {
            
            if(countBit(mask) == combinationLength) {
                string tmp = "";
                for(int i = 0; i < len; i++) {
                    if(mask & (1 << i))
                        tmp += characters[i];
                }
                sort(tmp.begin(),tmp.end());
                s.insert(tmp);   
            }
        }
        
        si = s.begin();
    }
    
    int countBit(unsigned int ui) {
        int count = 0;
        for(int i = 0; i < 32; i++) {
            count += (1u << i) & ui ? 1:0;
        }
        return count;
    }
    
    string next() {
        return *si++;
    }
    
    bool hasNext() {
        return si != s.end();   
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
