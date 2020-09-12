#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 501
#define INF 0x12345678
#define INF1 0x1234567812345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

int N;
int src[MAX][2] = {0};
int memo[MAX][MAX] = {0};

int dp(int st, int ed) {
     int i,j;
    
    if(st == ed) return 0;

    int &ret = memo[st][ed];
    if(ret) return ret;

    if(st == (ed - 1)) return ret = src[st][0]*src[st][1]*src[ed][1];

    long long min = INF1;
    for(i = st; i < ed; i++) {
        min = mymin(min, dp(st, i) + dp(i + 1, ed) + src[st][0]*src[i][1]*src[ed][1]);
    }

    return ret = min;
}

int main() {
    int i,j;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d %d", &src[i][0],&src[i][1]);

    printf("%d\n",dp(0, N - 1));

    return 0;
}
