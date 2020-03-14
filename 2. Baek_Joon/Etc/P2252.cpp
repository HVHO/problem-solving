// 백준 P2252 번 : 줄세우기
// 위상정렬

#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define deleteBit(x,a) ((x) & ~(1<<a))
#define checkBit(x,a) ((x) & (1<<(a)))
#define toggleBit(x,a) ((x) ^ (1<<(a)))

const int INF = 987654321;
const int MOD = 1e7 + 9;
const int NMAX = (int)32000+1;
const int MMAX = (int)1e5+1;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;


// linked list
struct NODE {
    int next;
    int val;
};

NODE nodePool[MMAX];
int nodeCnt = 0;
NODE linkedList[NMAX];

void push(int st, int ed) {
    int newNode = ++nodeCnt;
    nodePool[newNode].val = ed;
    nodePool[newNode].next = linkedList[st].next;
    linkedList[st].next = newNode;
}

//queue
int queue[NMAX];
int qhead = 0;
int qtail = 0;

void qpush(int x) {
    queue[qtail++] = x;
}

int qpop() {
    return queue[qhead++];
}

// sol()

int N, M;

int visit[NMAX];
int inDegree[NMAX];

int sol() {

    // init
    scanf("%d",&N);
    scanf("%d",&M);

    int s,e;
    for(int i = 0; i < M; i++) {
        scanf("%d %d",&s,&e);
        inDegree[e]++;
        push(s,e);
    }

    // find indegree == 0
    for(int i = 1; i <= N; i++)
        if(inDegree[i] == 0) qpush(i);

    int cnt = 0;
    while(cnt < N) {
        int c = qpop();
        printf("%d ",c);

        int cNode = linkedList[c].next;

        while(cNode) {
            inDegree[nodePool[cNode].val]--;
            if(!inDegree[nodePool[cNode].val]) qpush(nodePool[cNode].val);
            cNode = nodePool[cNode].next;
        } 

        cnt++;
    }

   return 0;
    
}


int main() {
    // printf("%d\n",sol());
    sol();
    return 0;
}