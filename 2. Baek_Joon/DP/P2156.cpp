#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001
#define INF 987654321

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define myabs(a) ((a) > 0 ? (a) : -(a))

using namespace std;

int N;
int arr[MAX];
int dp[MAX][2] = {0}; // 0 : 1잔으로 끝난 경우 1: 2잔으로 끝난 경우


int sol() {
    cin >> N;

    for(register int i = 0; i < N; i++) 
        cin >> arr[i];
    
    // dp
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    dp[1][0] = arr[1];
    dp[1][1] = arr[1] + arr[0];
    dp[2][0] = arr[2] + arr[0];
    dp[2][1] = arr[2] + arr[1];

    for(register int i = 3; i < N; i++) {
        int *cur = dp[i];

        cur[0] = mymax(mymax(dp[i - 2][0],dp[i - 2][1]), mymax(dp[i - 3][0], dp[i - 3][1])) + arr[i];
        cur[1] = dp[i - 1][0] + arr[i];
    }

    int ret = 0;

    for(register int i = N - 3; i < N; i++) {
        if(ret < dp[i][0]) ret = dp[i][0];
        if(ret < dp[i][1]) ret = dp[i][1];
    }

    return ret;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << sol() << endl;

    return 0;
}
