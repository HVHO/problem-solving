// 백준 P13907 번 : 세금
// dfs / dp
#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const long long INF = 987654321987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = (int)1e3+1;
const int MMAX = (int)3e4+1;
const int KMAX = (int)3e4;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N,M,K;
int S,D;


// linked list

struct NODE {
    int next;
    int ed;
    ll cost;
};

NODE nodePool[2*MMAX];
int nodeCnt = 0; 
NODE linkedList[NMAX];

void link(int st, int ed, int cost) {
    int newNode = ++nodeCnt;
    nodePool[newNode].ed = ed;
    nodePool[newNode].cost = cost;
    nodePool[newNode].next = linkedList[st].next;
    linkedList[st].next = newNode;
}

// priority queue
struct QUEUE {
    int cnt;
    int ed;
    ll cost;
};

QUEUE heap[NMAX*NMAX];
int heapCnt = 0;

bool comp(QUEUE a, QUEUE b) {
    return ( a.cost < b.cost ) || ((a.cost == b.cost) && (a.cnt < b.cnt));
}


void push(QUEUE a) {
    int idx = ++heapCnt;

    heap[idx] = a;

    while(idx > 1 && comp(heap[idx],heap[idx/2])) {
        QUEUE tmp;
        tmp = heap[idx];
        heap[idx] = heap[idx/2];
        heap[idx/2] = tmp;
        idx/=2;
    }
}

QUEUE pop() {
    QUEUE ret = heap[1];

    int r,l,c,n;
    c = 1;

    heap[1] = heap[heapCnt--];

    while(1) {
        n = 0;
        l = 2*c;
        r = 2*c + 1;
        if(l <= heapCnt && comp(heap[l],heap[c])) n = l;
        if(r <= heapCnt && comp(heap[r],heap[c]) && comp(heap[r],heap[l])) n = r;

        if(!n) break;

        QUEUE tmp = heap[c];
        heap[c] = heap[n];
        heap[n] = tmp;

        c = n; 
    }

    return ret;
}



// dijkstra 

ll mem[NMAX][NMAX]; // i 번째 거쳐 도착점에 도달하는 최소 거리

void dijkstra() {

    // init
    for(int i = 0; i <= N ; i++) {
        for(int j = 0; j <= N; j++) {
            mem[i][j] = INF;
        }
    }

    mem[S][0] = 0;
    push(QUEUE{0,S,0});

    while(heapCnt) {

        QUEUE cur = pop();

        // printf("%d %d %d \n", cur.ed, cur.cnt, cur.cost);

        if(cur.cnt == N - 1) continue;
        if(cur.cost > mem[cur.ed][cur.cnt]) continue;

        bool find = false;

        for(int i = 0; i < cur.cnt; i++) {
            if(mem[cur.ed][i] < cur.cost) find = true;
        }

        if(find) continue;

        int cNode = linkedList[cur.ed].next;

        while(cNode) {

            int cnt = cur.cnt + 1;
            int ed = nodePool[cNode].ed;
            int cost = cur.cost + nodePool[cNode].cost;

            if(ed == S) {
                
            } else {
                if(mem[ed][cnt] > cost) {
                    mem[ed][cnt] = cost;
                    push(QUEUE{cnt, ed, cost});
                }
            }

            cNode = nodePool[cNode].next;
        }
    }

}

ll getMin() {
    ll min = INF;
    for(int i = 0; i < N; i++) {
        if(min > mem[D][i]) min = mem[D][i];
    }
    return min;
}

void sol() {

    scanf("%d %d %d",&N,&M,&K);
    scanf("%d %d",&S,&D);

    int a,b,w;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d",&a,&b,&w);
        link(a,b,w);
        link(b,a,w);
    }

    dijkstra();
    printf("%lld\n",getMin());
    
    int p;
    for(int i = 0; i < K; i++) {
        scanf("%d",&p);
        for(int j = 0; j < N; j++) {
            mem[D][j] += j*p;
        }
        printf("%lld\n",getMin());
    }

}



int main() {
    
    sol();
    // printf("%d",sol());
    return 0;
}

