// 677. Map Sum Pairs

struct Trie {
    bool finish;
    Trie* next[26];
    
    Trie() {
        memset(next, 0, sizeof(next));
        finish = false;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) 
            if (next[i])
                delete next[i];
    }
    
    void insert(const char* key) {
        if(*key == '\0') {
            finish = true;   
        } else {
            int cur = *key - 'a';
            if(!next[cur])
                next[cur] = new Trie();
            next[cur] -> insert(key+1);
        }
    }
    
    Trie* find(const char* key) {
        if(*key == '\0')
            return this;
        int cur = *key - 'a';
        if(!next[cur]) return nullptr;
        else return next[cur] -> find(key+1);
    }
};


class MapSum {
public:
    
    unordered_map<string,int> m;
    Trie* t;
    /** Initialize your data structure here. */
    MapSum() {
        m.clear();
        t = new Trie();
    }
    
    void insert(string key, int val) {
        if(m.find(key) == m.end()) {
            t->insert(key.c_str());
        }
        m[key] = val;   
    }
    
    
    
    int sum(string prefix) {
        queue<pair<Trie*,string>> q;
        vector<string> v;
        
        q.push({t->find(prefix.c_str()),prefix});
        
        while(q.size()) {
            auto [_t,path] = q.front();
            q.pop();
            
            if(_t == nullptr) continue;
            if(_t -> finish) v.push_back(path);
            
            for(int i = 0; i < 26; i++) {
                if(_t -> next[i]) {
                    q.push({_t->next[i], path + (char)('a' + i)});
                }
            }            
        }
        
        int res = 0;
        for(auto s: v) {
            res += m[s];
        }
        
        return res;
        
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
