#include <string>
#include <vector>
#include <map>

using namespace std;

int idx;
map<string, int> trans;

int transfer( string s) {
    if(trans.find(s) != trans.end()) return trans[s];
    trans.insert(make_pair(s,idx++));
    return idx - 1;
}

void dfs(int c, int d, vector<int> & count, vector<vector<int>> &adj_list) { // should not visit dest 
    count[c]++;
    if(c == d) return;

    for(int n: adj_list[c]) {
        dfs(n, d, count, adj_list);    
    }
}

int solution(string depar, string hub, string dest  , vector<vector<string>> roads) {
    int answer = -1;

    trans.insert(make_pair(depar,0));
    trans.insert(make_pair(hub,1));
    trans.insert(make_pair(dest,2));
    idx = 3;

    // prepare adj list ( adj mat may sle )
    vector<vector<int>> adj_list(10001);

    for(auto road : roads) {
        int s = transfer(road[0]);
        int e = transfer(road[1]);
        adj_list[s].push_back(e);
    }

    // dfs d -> h && h -> d

    int dtoh = 0;
    vector<int> count1(10001, 0);
    dfs(0,1,count1,adj_list);
    dtoh = count1[1];


    int htoe = 0;
    vector<int> count2(10001, 0);
    dfs(1,2,count2,adj_list);
    htoe = count2[2];

    answer = dtoh*htoe;

    return answer;
}
