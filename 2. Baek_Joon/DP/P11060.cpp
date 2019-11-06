#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1101
#define INF 987654321

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define myabs(a) ((a) > 0 ? (a) : -(a))

using namespace std;

int N;
int arr[MAX];
int dp[MAX] = {0};


int sol() {
    cin >> N;

    for(register int i = 0; i < N; i++) 
        cin >> arr[i];
    
    // dp
    dp[0] = 1;

    for(register int i = 0; i < N; i++) {
        if(!dp[i]) continue;

        for(register int j = 1; j <= arr[i]; j++)
            if(!dp[i + j] || (dp[i + j] > dp[i] + 1))
                dp[i + j] = dp[i] + 1;
    }

    if(dp[N-1]) return dp[N-1] - 1;
    else return -1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << sol() << endl;

    return 0;
}
