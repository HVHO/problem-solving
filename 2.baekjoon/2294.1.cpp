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
    
    // dp
    dp[0] = 0;
    for(register int i = 0; i < aIdx; i++)
        for(register int j = arr[i]; j <= K; j++ )
            if(dp[j] > dp[j - arr[i]]) dp[j] = dp[j - arr[i]] + 1;
    
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
