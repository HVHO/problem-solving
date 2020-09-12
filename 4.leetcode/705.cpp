// 705. Design HashSet

#define HASH_SIZE (int)(1e6/8+1)
#define ad(x,y) ((x)[(y)/8]|=(1u<<(y)%8))
#define rm(x,y) ((x)[(y)/8]&=~(1u<<(y)%8))
#define cont(x,y) ((x)[(y)/8]&(1u<<(y)%8))

class MyHashSet {
public:
    unsigned char hash[HASH_SIZE];
    /** Initialize your data structure here. */
    MyHashSet() {
        for(int i = 0; i<HASH_SIZE; i++ )
            hash[i] = 0;
    }
    
    void add(int key) {
        ad(hash,key);
    }
    
    void remove(int key) {
        rm(hash,key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return cont(hash,key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */