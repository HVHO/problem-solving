#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1002
#define HMAX 100002
#define INF 0x12345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

struct vw {
    int v;
    int w;

    vw(int a = 0, int b = 0) {v = a; w = b;}
};

// main()
int V, E;
int adjMat[MAX][MAX];
// heap
vw heap[HMAX];
int hcnt = 0;
// prim
int d[MAX];
int visit[MAX] = {0};

void init() {

    hcnt = 0;

    for(register int i = 0; i < MAX; i++) {
        d[i] = INF;
       for(register int j = 0; j < MAX; j++) {
            adjMat[i][j] = INF;
        }
    }

}

void heapPush(vw newEdge) {

    heap[++hcnt] = newEdge;
    register int idx = hcnt;

    while(idx > 1 && heap[idx].w < heap[idx/2].w) {
        vw tmp = heap[idx];
        heap[idx] = heap[idx/2];
        heap[idx/2] = tmp;
        idx/=2;
    }

}

vw heapPop() {

    vw ret=heap[1];
    heap[1] = heap[hcnt--];

    int c = 1, l = 2, r = 3, n = 0;
    while(l <= hcnt || r <= hcnt) {
        n = 0;
        if( l <= hcnt && heap[c].w > heap[l].w ) n = l;
        if( r <= hcnt && heap[c].w > heap[r].w && heap[l].w > heap[r].w) n = r;

        if(!n) break;

        vw tmp = heap[c];
        heap[c] = heap[n];
        heap[n] = tmp;
        
        c = n;
        l = 2*c;
        r = 2*c + 1;
    }

    return ret;
}

int prim() {

    heapPush(vw(1,0));

    while(hcnt) {

        vw c = heapPop();

        if(visit[c.v]) continue;
        visit[c.v] = 1;
        d[c.v] = c.w;
        //printf("%d %d\n",c.v,c.w);

        for(register int i = 1; i <= V; i++) {
            
            if(!visit[i] && d[i] > adjMat[c.v][i]) {
                heapPush(vw(i,adjMat[c.v][i]));
            }
        }
    }

    int ret = 0;
    for(register int i = 1; i <= V; i++) {
        ret += d[i];
    }

    return ret;
}


int main() {
    int i,j;
    init();

    scanf("%d", &V);

    scanf("%d", &E);

    int u,v,w;
    for(register int i = 0; i < E; i++) {
        scanf("%d %d %d",&u,&v,&w);
        adjMat[u][v] = adjMat[v][u] = w;
   }

    printf("%d\n", prim());

    return 0;
}
