// 백준 P5719 번 : 거으 최단경로
// dijkstra apply
#include <stdio.h>
#include <vector>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const int MOD = (int)1e7 + 19;
const int NMAX = (int)501;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N,M;
int S,D;
int map[NMAX][NMAX];
int d[NMAX];
vector <int> p[NMAX];

// heap
int heap[NMAX*NMAX];
int hcnt = 0;

void push(int n) {
    heap[++hcnt] = n;
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
    int c=1,n,l,r;
    while(true) {
        n = 0;
        l = 2*c;
        r = 2*c + 1;

        if(l<=hcnt && d[heap[l]]<d[heap[c]]) n = l;
        if(r<=hcnt && d[heap[r]]<d[heap[c]] && d[heap[r]]<d[heap[l]]) n = r;
        if(!n) break;

        int tmp = heap[n];
        heap[n] = heap[c];
        heap[c] = tmp;
        c = n;
    }
    return ret;
}


void init() {

    hcnt = 0;
    for(int i = 0; i < NMAX; i++) {
        d[i] = INF;
        p[i].clear();
    }
}


int dijkstra(int st, int ed) {

    init();

    d[st] = 0;
    push(st);

    while(hcnt) {
        int c = pop();
        for(int i = 0; i < N; i++) {
            if(i != c && d[i] != INF && (d[i] == (d[c] + map[c][i]))) {
                p[i].push_back(c);
            } else if(d[i] > ( d[c] + map[c][i] )) {
                d[i] = d[c] + map[c][i];
                p[i].clear();
                p[i].push_back(c);
                push(i);
            } 
        }
    }

    if(d[ed] != INF) return d[ed];
    else return -1;
}
void deleteMinPath(int _c) {
    int _p;
    for(int i = 0; i < p[_c].size(); i++) {
        _p = p[_c][i];
        map[_p][_c] = INF;
        deleteMinPath(_p);
    }
}
int sol() {

    // init
    for(int i = 0; i < NMAX; i++) {
        for(int j = 0; j < NMAX; j++)
            if(i!=j) map[i][j] = INF;
            else map[i][j] = 0;
    }

    scanf("%d %d",&N,&M);
    // end condition
    if(N == 0 && M == 0) return 0;    

    scanf("%d %d",&S,&D);

    int s,e,c;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d",&s,&e,&c);
        map[s][e] = c;
    }
    // dijkstra

    int ret = dijkstra(S,D);

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < p[i].size(); j++)
    //         printf("%d ",p[i][j]);
    //     printf("\n");
    // }

    int ret1;
    if(ret1 == -1) return -1;
    
    // delete minimum path edge
    deleteMinPath(D);

    ret1 = dijkstra(S,D);
    
    return ret1;    
}



int main() {
    int TC;
    // scanf("%d",&TC);
    // for(int i = 1; i <= TC; i++) {
    //     // printf("#%d %d\n",i,sol());
    //     printf("#%d ",i);
    //     sol();
    // }
    int ret = 0;
    while(true){
        ret = sol();
        if(!ret) break;
        printf("%d\n",ret);
    }
    // printf("%d\n",sol());
    // sol();
    return 0;
}