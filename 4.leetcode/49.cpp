// 49. Group Anagrams


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            auto sorted = s; 
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(s);
        }
        vector<vector<string>> res;
        for (auto [k, v] : m) { 
            res.push_back(v);
        }
        return res;
    }
};
