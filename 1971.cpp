// 1971. Find if Path Exists in Graph

class Solution {

    int root[200001] = {0, };
    int dep[200001] = {0, };

    int find(int n) {
        if(root[n] == n) return n;
        else return root[n] = find(root[n]);
    }

    void make(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(dep[px] > dep[py]) {
            swap(px,py);
        }

        if(dep[px] == dep[py]) {
            dep[px] += 1;
            root[py] = px;
            return;
        }

        root[px] = py;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        for(int i = 1; i <= n; i++) {
            root[i] = i;
            dep[i] = 1;
        }

        for(int i = 0; i < edges.size(); i++) {
            auto e = edges[i];
            make(e[0],e[1]);
        }

        return find(source) == find(destination);
    }
};
