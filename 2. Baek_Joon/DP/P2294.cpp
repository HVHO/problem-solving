#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define DMAX 10005
#define NMAX 101
#define INF 987654321

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define myabs(a) ((a) > 0 ? (a) : -(a))

using namespace std;

int N,K;
int dp[DMAX];
int arr[NMAX];
int aIdx=0;


void init() {
    for(register int i = 0; i < DMAX; i++) dp[i] = INF;
}

int sol() {
    init();

    cin >> N >> K;

    int tmp;
    for(register int i = 0; i < N; i++)  {
        cin >> tmp;
        if(tmp > K) continue;

        bool flag = false;
        for(register int j = 0; j < aIdx; j++) { // 중복제거
            if(arr[j] == tmp) flag = true;
        }
        if(flag) continue;
        arr[aIdx++] = tmp;
    }

    // 초기화
    for(register int i = 0; i < aIdx; i++) {
        for(register int j = 1; j <= DMAX/arr[i]; j++) {
            int &cur = dp[arr[i]*j];
            if(cur > j) cur = j;
        }
    }

    // dp
    for(register int i = 1; i <= K; i++) {

        for(register int j = 1; j <= i/2; j++) {
            if(dp[i - j] != INF && dp[j] != INF && dp[i] > dp[i - j] + dp[j])
                dp[i] = dp[i-j] + dp[j];
        }

        if(dp[i] == INF) continue;
        
        for(register int j = 1; j <= DMAX/i; j++) {
            int &cur = dp[i*j];
            if(cur > j) cur = j*dp[i];
        }

        // printf("dp[%d] : %d\n",i,dp[i]);

    }
    
    if(dp[K] != INF) return dp[K];
    else return -1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << sol() << endl;

    return 0;
}
