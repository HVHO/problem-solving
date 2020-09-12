#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;


bool check(char c) {
    if(('a' <= c && c <= 'z') ||
       ('A' <= c && c <= 'Z') ||
       ('0' <= c && c <= '9') ||
       (c == '-') ||
       (c == '_') ||
       (c == '.')
       ) return true;
    return false;
}

string solution(string new_id) {
    string answer = "";
    
    answer = new_id;
    // to lower case
    boost::algorithm::to_lower(answer);
    // delete exeception case
    for(int i = 0; i < answer.size(); i++) {
        if(!check(answer[i])) {
            answer.erase(i,1);
            i--;    
        }
    }
    // replace .. to .
    for(int i = 0; i < answer.size(); i++) {
        if(answer[i]=='.' && answer[i+1]=='.') {
            answer.erase(i,1);
            i--;
        }
    }
    // remove first/end .
    if(*answer.begin() == '.') 
        answer.erase(0,1);
    if(*(answer.end()-1) == '.') 
        answer.erase(answer.size()-1,1);
    
    // if empty, change to a
    if(answer.empty())
        answer = "a";
        
    // if len>=16, cut out after idx 15
    if(answer.length() > 15);
        answer = answer.substr(0,15);
    if(answer[14] == '.')
        answer.erase(14,1);
    
    // if len<=2, make len = 3
    if(answer.length() < 3) {
        while(answer.length() < 3){
            answer.push_back(answer[answer.length()-1]);
        }
    }
    
    return answer;
}