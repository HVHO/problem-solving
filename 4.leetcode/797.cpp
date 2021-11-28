// 797. All Paths From Source to Target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        queue<vector<int>> pathQ;
        vector<vector<int>> answer;
        
        int dst = graph.size() - 1;
        
        pathQ.push({0});
        
        while(pathQ.size()) {
            auto path = pathQ.front();
            pathQ.pop();
            
            int n = path.size();
            
            if(path[n-1] == dst) {
                answer.push_back(path);
                continue;
            }
            
            for(auto n: graph[path[n-1]]) {
                auto tpath = path;
                tpath.push_back(n);
                pathQ.push(tpath);
            }
        }
        
        return answer;      
    }
};
