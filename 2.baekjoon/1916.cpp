#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define deleteBit(x,a) ((x) & ~(1<<a))
#define checkBit(x,a) ((x) & (1<<(a)))
#define toggleBit(x,a) ((x) ^ (1<<(a)))

const int INF = 987654321;
const int MOD = 1e7 + 9;
const int NMAX = (int)1e3+1;
const int MMAX = (int)1e5+1;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

int N,M;
int map[NMAX][NMAX];
int d[NMAX];
int st, ed;

// heap
int heap[MMAX];
int hcnt = 0;

void push(int x) {
    heap[++hcnt] = x;
    int idx = hcnt;

    while(idx > 1 && d[heap[idx]] < d[heap[idx/2]]) {
        int tmp = heap[idx];
        heap[idx] = heap[idx/2];
        heap[idx/2] = tmp;
        idx/=2;
    }
}

int pop() {
    int ret = heap[1];
    heap[1] = heap[hcnt--];

    int c = 1,l,r,n;
    while(true) {
        n = 0;
        l = 2*c;
        r = 2*c + 1;
        if(l <= hcnt && d[heap[l]] < d[heap[c]]) n = l;
        if(r <= hcnt && d[heap[r]] < d[heap[c]] && d[heap[r]] <d[heap[l]]) n = r;
        if(!n) break;
        int tmp = heap[n];
        heap[n] = heap[c];
        heap[c] = tmp;
        c = n;
    }
    return ret;
}

// dikjstra

int dikjstra() {

    d[st] = 0;
    push(st);

    while(hcnt) {
        int c = pop();
        if(c == ed) return d[c];
        // printf("c : %d e : %d\n",c,d[c]);
        for(int i = 1; i <= N; i++ ) {
            if(d[i] > d[c] + map[c][i]) {
                d[i] = d[c] + map[c][i];
                push(i);
            }
        }

    }

    return -1;
}

int sol() {

    // init
    for(int i = 0; i < NMAX; i++) {
        for(int j = 0; j < NMAX; j++)
            map[i][j] = INF;
        d[i] = INF;
        map[i][i] = 0;

    }

    scanf("%d",&N);
    scanf("%d",&M);

    for(int i = 0; i < M; i++) {
        int s,e,c;
        scanf("%d %d %d",&s, &e, &c);
        if(map[s][e] > c) map[s][e] = c;
    }
    
    scanf("%d %d",&st,&ed);

    return dikjstra();
}


int main() {
    printf("%d\n",sol());
    // sol();
    return 0;
}