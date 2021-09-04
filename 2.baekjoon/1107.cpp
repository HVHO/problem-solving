#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 5001
#define INF 0x12345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define myabs(a) ((a) > 0 ? (a) : -(a))

using namespace std;

int button[10] = {0};
int tmp[10] = {0};
int visit[10] = {0};
int ret = INF;
int N;

int arrToint(int n) {
    int r = 0;
    for(int i = n ; i--;) {
        r*=10;
        r+=tmp[i];
    }
    return r;
}

void dfs(int depth) {
    
    if ( depth > 6) return;
    
    if(depth) {
        int cur = arrToint(depth);
        int diff = depth + myabs(N - cur);
        if(ret > diff) {
            //printf("depth : %d, diff : %d, cur : %d ,ret %d -> %d\n",depth,myabs(N-cur), cur, ret, diff);
            ret = diff;
        }
    }
    

    for(int i = 0; i < 10; i++) {
        if(!button[i]) continue;
         tmp[depth] = i;
         dfs(depth + 1);
    }
}

int main() {

    for(register int i = 0; i < 10; i++)
        button[i] = 1;

    scanf("%d",&N);
    int t;
    scanf("%d", &t);

    for(register int i = 0; i < t; i++) {
        int tmp;
        scanf("%d",&tmp);
        button[tmp] = 0;
    }

    dfs(0);
    if(ret > myabs(N - 100)) ret = myabs(N - 100);

    printf("%d\n",ret);
    
    return 0;
}
