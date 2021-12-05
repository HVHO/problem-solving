// 백준 P2533 번 : 사회망 서비스(sns)
// dfs / dp
#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))

const int INF = 987654321;
const int MOD = 1e7 + 9;
const int NMAX = (int)1e6 + 1;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

// linked list

struct NODE {
    int next;
    int val;
};

NODE nodePool[2*NMAX];
int nodeCnt = 0;
NODE linkedList[NMAX];

void push(int st, int ed) {
    int newNode = ++nodeCnt;
    nodePool[newNode].val = ed;
    nodePool[newNode].next = linkedList[st].next;
    linkedList[st].next = newNode;
}

// dfs & dp
int N;
int mem[NMAX][2]; // 자신이 얼리어답터일 경우 0 아닐경우 1
bool visit[NMAX];
bool early[NMAX];

void dpInit() {
    for(int i = 1; i <= N; i++){
        mem[i][0] = INF;
        mem[i][1] = INF;
    }
}

int dfs(int cur) {

    // 현재 얼리어답터일 경우
    bool curEarly = early[cur];
    int &ret = mem[cur][(curEarly ? 0 : 1)];

    if(ret != INF) return ret;
     
    
    ret = 0;
    int cNode = linkedList[cur].next;
    
    while(cNode) {

        if(!visit[nodePool[cNode].val]) {
            visit[nodePool[cNode].val] = true;
            
            int ret1;
            // dfs
            early[nodePool[cNode].val] = true;
            ret1 = dfs(nodePool[cNode].val);
            if(curEarly) {
                early[nodePool[cNode].val] = false;
                ret1 = mymin(ret1,dfs(nodePool[cNode].val));
            }
            ret += ret1;
            visit[nodePool[cNode].val] = false;
        }
        cNode = nodePool[cNode].next;
    }
    ret += (curEarly ? 1 : 0);

    return ret;
}


int sol() {

    scanf("%d",&N);

    int st,ed;

    for(int i = 0; i < (N - 1); i++) {
        scanf("%d %d",&st,&ed);
        push(st,ed);
        push(ed,st);
    }
    
    for(int i = 1; i <= N; i++) 
    // init
    dpInit();
    // 
    int ret;
    visit[1] = true;
    early[1] = true;
    ret = dfs(1);
    early[1] = false;
    ret = mymin(ret,dfs(1));

    return ret;
}


int main() {
    printf("%d\n",sol());
    // sol();
    return 0;
}