#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


pair<vector<int>, int> parse_info(string s) {
    
    stringstream ss(s);
    string token;
    int a,b,c,d;
    
    ss >> token;
    if(!token.compare("cpp")) a = 0;
    else if(!token.compare("java")) a = 1;
    else a = 2;
        
    ss >> token;
    if(!token.compare("backend")) b = 0;
    else b = 1;
    
    ss >> token;
    if(!token.compare("junior")) c = 0;
    else c = 1;
    
    ss >> token;
    if(!token.compare("chicken")) d = 0;
    else d = 1;
    
    int num;
    ss >> num;
    
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    res.push_back(d);
    
    return make_pair(res,num);
}

pair<vector<int>,int> parse_query(string s) {
    stringstream ss(s);
    string token;
    int a,b,c,d;
    
    ss >> token;
    if(!token.compare("cpp")) a = 0;
    else if(!token.compare("java")) a = 1;
    else if(!token.compare("python")) a = 2;
    else a = -1;
        
    ss >> token;
    ss >> token;
    if(!token.compare("backend")) b = 0;
    else if(!token.compare("frontend")) b = 1;
    else b = -1;
    
    ss >> token;
    ss >> token;
    if(!token.compare("junior")) c = 0;
    else if(!token.compare("senior")) c = 1;
    else c = -1;
    
    ss >> token;
    ss >> token;
    if(!token.compare("chicken")) d = 0;
    else if(!token.compare("pizza")) d = 1;
    else d = -1;
    
    int num;
    ss >> num;
    
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    res.push_back(d);
    
    return make_pair(res,num);
}

int bin_search(vector<int> list, int num) {
    
    int l = 0;
    int r = list.size();
    int m;
    
    if(!list.size()) return 0;
    
    while(l<r) {

        m = (r+l)/2;
        // printf("l: %d r: %d m: %d val: %d num: %d\n", l, r, m, list[m], num);
        if(list[m] >= num) r = m;
        else l = m + 1;
    }
    
    return (list.size() - l);
}

int do_query(int a, int b, int c, int d, int num, vector<int> cache [3][2][2][2]) {
    
    int res = 0;
    
    vector<vector<int>> query(4);
    
    // printf("do query: %d %d %d %d\n",a,b,c,d);
    
    if(a == -1){
        query[0].push_back(0);query[0].push_back(1);query[0].push_back(2);    
    } else {
        query[0].push_back(a);  
    }
    
    if(b == -1) {
        query[1].push_back(0);query[1].push_back(1);  
    } else {
         query[1].push_back(b);
    }
    
    if(c == -1) {
        query[2].push_back(0);query[2].push_back(1);  
    } else {
         query[2].push_back(c);
    }
    
    if(d == -1) {
        query[3].push_back(0);query[3].push_back(1);  
    } else {
         query[3].push_back(d);
    }
    
    
    // printf("query: %d %d %d %d %d\n", a, b, c, d,num);
    for(auto i: query[0])
        for(auto j: query[1])
            for(auto k: query[2])
                for(auto l: query[3]) {
                    // printf("search: %d %d %d %d %d\n", i,j,k,l,num);
                    res += bin_search(cache[i][j][k][l],num);
                }
                 
    // printf("res: %d\n", res);
    // printf("\n");
    
    return res;
    
}

// 언어 3, 직군 2, 경력 2, 음식 2
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<int> cache[3][2][2][2];
    
    // parse info
    for(int i = 0; i < info.size(); i++) {
        auto [idx,num] = parse_info(info[i]);
        // printf("%d %d %d %d %d\n", idx[0],idx[1],idx[2],idx[3],num );
        cache[idx[0]][idx[1]][idx[2]][idx[3]].push_back(num);
    }
    
    // sort cache
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++) {
                    sort(cache[i][j][k][l].begin(),cache[i][j][k][l].end());
                    for(int m = 0; m < cache[i][j][k][l].size(); m++)
                        // printf("%d %d %d %d : %d ",i,j,k,l, cache[i][j][k][l][m]);
                    printf("\n");
                }
                    
                    
    
    printf("\n");
    // search query
    for(int i = 0; i < query.size(); i++) {
        auto [idx,num] = parse_query(query[i]);
        // printf("%d %d %d %d %d\n", idx[0],idx[1],idx[2],idx[3],num );
        answer.push_back(do_query(idx[0],idx[1],idx[2],idx[3],num, cache));
    }
    
    return answer;
}