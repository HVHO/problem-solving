#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 5001
#define INF 0x12345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

// main()
char src[MAX];
char rev[MAX];
// lcs
int memo[MAX][MAX] = {0};


void init() {
    for(register int i = 0; i < MAX; i++) {
        for(register int j = 0; j < MAX; j++)
            memo[i][j] = -1;
    }
}

int lcs(int i, int j) {

    if(i < 0 || j < 0) return 0;

    int &ret = memo[i][j];

    if(ret != -1) return ret;

    if(src[i] == rev[j]) ret = lcs(i - 1 , j - 1) + 1;
    else {
        int l = lcs(i - 1, j);
        int r = lcs(i, j - 1);
        ret = l > r ? l : r;
    }

    return ret;
}

int ztrlen(char* str) {
    int cnt = 0;
    while(str[cnt] != '\0') {
        cnt++;
    }
    return cnt;
}


int main() {

    init();
    int len = 0;
    scanf("%d",&len);
    scanf("%s", src);
    //int len = ztrlen(src);

    for(register int i = 0; i < len; i++) {
        rev[i] = src[len - i - 1];
    }

    int ret = 0;
    for(register int i = 0; i < len; i++) {
        for(register int j = 0; j < len; j++)
            if(ret < lcs(i,j)) ret = lcs(i,j);
    }
    //printf("ret : %d\n",ret);

    printf("%d\n",len - ret);
    return 0;
}
