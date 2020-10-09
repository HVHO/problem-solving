#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


using namespace std;

int solution(int k, vector<int> score) {
    int answer = 0;

    map<int, vector<int>> li; // diff, list , sorted list by diff

    for(int i = 0; i < score.size() - 1; i++) {
        int diff = score[i] - score[i+1];
        // push(li, diff, i);
        if(li.find(diff)!=li.end()) {
            li[diff].push_back(i);
        } else {
            li.insert(make_pair(diff,vector<int>(1,i)));
        }
    }

    vector<bool> check(score.size(), false);

    for(auto entity: li) {
        if(entity.second.size() >= k) {
            for(auto idx: entity.second) {
                check[idx] = true;
                check[idx+1] = true;
            }
        }
    }

    for(auto c: check) {
        if(!c) answer++;
    }


    return answer;
}
