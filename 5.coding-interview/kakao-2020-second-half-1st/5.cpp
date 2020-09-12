#include <string>
#include <vector>

using namespace std;

int convert_time(string time) {
    int hour = 10*(time[0] - '0') + time[1] - '0';
    int minute = 10*(time[3] - '0') + time[4] - '0';
    int second = 10*(time[6] - '0') + time[7] - '0';
    
    return hour*60*60 + minute*60 + second;
}

string deconvert_time(int time) {
    int hour = time/3600;
    int minute = (time - hour*3600)/60;
    int second = (time - hour*3600 - minute*60);
    
    char buf[10];
    sprintf(buf,"%d%d:%d%d:%d%d",hour/10,hour%10,minute/10,minute%10,second/10,second%10);
    string res(buf);
    
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int p_t = convert_time(play_time);
    int a_t = convert_time(adv_time);
    
    vector<int> count(p_t+1);
    
    for(string s: logs) {
        int s_t = convert_time(s.substr(0,8));
        int e_t = convert_time(s.substr(9,8));
        
        for(int i = s_t; i < e_t; i++)
            count[i]++;
    }
    
    long long c = 0;
    for(int i = 0; i < a_t; i++) {
        c += count[i];
    }
    long long max = c;
    int res = 0;
    
    for(int i = a_t; i <= p_t; i++) {
        c -= count[i - a_t];
        c += count[i];
        if(c > max) {
            max = c;
            res = i - a_t + 1;
        }
    }
    
    
    return deconvert_time(res);
}