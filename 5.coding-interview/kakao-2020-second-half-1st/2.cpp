#include <string>
#include <vector>
#include<algorithm>

using namespace std;

// 26C10 = 5311735

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    int c_size = course.size();
    int o_size = orders.size();

    // init
    vector<char> alpha_list;
    for(string o: orders) {
        for(int i = 0; i < o.size(); i++) {
            bool flag = false;
            for(int j = 0; j < alpha_list.size(); j++){
                if(o[i] == alpha_list[j]) flag = true;
            }
            if(!flag) alpha_list.push_back(o[i]);
        }
    }
    sort(alpha_list.begin(),alpha_list.end());
    // for(char c: alpha_list) {
    //     printf("%c ",c);
    // }
    // printf("\n");
    int a_size = alpha_list.size();
    
    
    for(int i = 0; i < c_size; i++ ) {
        
        // permutation init
        vector<int> perm(a_size - course[i], 0);
        for(int j = 0; j < course[i]; j++) {
           perm.push_back(1);
        }
        sort(perm.begin(),perm.end());
        // result vector init
        vector<vector<char>> res;
        int max = 0;
        
        do{
            int count = 0;
            
            // printf("permu: ");
            // for(int j = 0; j < perm.size(); j++) {
            //     printf("%d ",perm[j]);
            // }
            //     printf("\n");
            for(int j = 0; j < orders.size(); j++) {
                bool flag = true;
                for(int k = 0; k < a_size; k++) {
                    if(perm[k] && (orders[j].find(alpha_list[k])==std::string::npos)) flag = false;
                }
                if(flag) count++;
                
            }            
            
            vector<char> c;
            for(int j = 0; j < a_size; j++) {
                if(perm[j]) c.push_back(alpha_list[j]);
            }
            
            if(count >= 2 && count == max) {
                res.push_back(c);
            } else if(count >= 2 && count > max) {
                res.clear();
                res.push_back(c);
                max = count;
            }
            
        } while(next_permutation(perm.begin(),perm.end()));
        

            for(int j = 0; j < res.size(); j++){
                string s;
                for(int k = 0; k < res[j].size(); k++)
                    s.push_back(res[j][k]);
                    answer.push_back(s);    
        }
    }
        
        
    sort(answer.begin(), answer.end());
    return answer;
}