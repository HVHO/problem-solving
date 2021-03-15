//	535. Encode and Decode TinyURL    

#include <map>

using namespace std;

class Solution {
    map<string,string> store;
    
    
    string gethash() {
        string a;
        for(int i = 0; i < 6; i++) {
            int idx = rand()%3;
            switch(idx) {
                case 0:
                    a.push_back('a' + rand()%26);
                case 1:
                    a.push_back('A' + rand()%26);
                case 2:
                    a.push_back('0' + rand()%10);
            }
        }
        return a;
    }
    
public:
    
    Solution() {
        store = map<string,string>();
    } 
        
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl;
        do {
            shortUrl = gethash();
        } while (store.find(shortUrl) != store.end());
        
        store[shortUrl] = longUrl;
        
        return "http://tinyurl.com/" + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return store[shortUrl.substr(19,shortUrl.length())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
