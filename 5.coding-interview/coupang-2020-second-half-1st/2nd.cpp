#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define ctn(c) (c - 0) // char to number

using namespace std;

pair<int,int> parse(string s) {
    static int montoday[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int time = 0; // time in second form 10/1 00:00:00

    int mon = 10*ctn(s[0]) + ctn(s[1]);
    int day = 10*ctn(s[3]) + ctn(s[4]);

    int hour = 10*ctn(s[6]) + ctn(s[7]);
    int min = 10*ctn(s[9]) + ctn(s[10]);
    int sec = 10*ctn(s[12]) + ctn(s[13]);

    int work = 10*ctn(s[15]) + ctn(s[16]);

    // cout <<"mon: " << mon << "day" << day <<"hour" <<hour<<"min"<<min<<"sec"<<sec<<"work"<<work<<endl;

    for(int i = 1; i < mon; i++) {
        time += 86400*montoday[i];
    }
    time += 86400*(day - 1);
    time += 3600*hour;
    time += 60*min;
    time += sec;

    return pair<int,int>(time,60*work);
}

int match(vector<int> kiosk) {

    int min = 0x12345678;
    int res = 0;
    for(int i = 0; i < kiosk.size(); i++) {
        cout << i << ": " << kiosk[i] << endl;
        if(kiosk[i] < min ) {
            res = i;
            min = kiosk[i];
        }
    }

    // cout << "matched" << res << endl;
    return res;
}

int solution(int n, vector<string> customers)
{
    int answer = 0;

    vector<int> count(n,0);
    vector<int> kiosk(n,0);
    vector<queue<int>> kiosk_queue(n);

    vector<pair<int,int>> parsed;
    for( auto customer: customers) {
        parsed.push_back(parse(customer));
    }

    int ts = parsed[0].first;
    int idx = 0;
    while(idx < parsed.size()) {
        // cout << "ts: " << ts << endl;
        // if customer come in, queue the kiosk

        int cur = match(kiosk);
        count[cur]++;
        // cout <<"work: "<< parsed[idx].second<<endl;
        kiosk_queue[cur].push(parsed[idx].second);
        idx++;


        int time_diff = parsed[idx].first - ts;
        // cout<< "timediff: " << time_diff<<endl;

        // doing ts update
        for(int i = 0; i < kiosk.size(); i++) {
            if(!kiosk_queue[i].empty()) {
                if(kiosk[i] < 0) kiosk[i] = 0;
                kiosk[i] += kiosk_queue[i].front();
                kiosk_queue[i].pop();
            }
            kiosk[i]-=time_diff;
        }
        ts+=time_diff;
    }    


    for(int i: count) {
        // cout << i << " " ;
        if(answer < i) answer = i;
    }

    return answer;
}
