#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define VMAX 1001
#define HMAX 100001
#define INF 0x12345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))

using namespace std;


// disjoint set
int root[VMAX];
int depth[VMAX];

void makeSet() {
    for(register int i = 0; i < VMAX; i++) {
        root[i] = i;
        depth[i] = 0;
    }
}

int _find(int x) {

    int cur = x;
    int parent = root[cur];

    while( cur != parent) {
        //printf("find : %d\n",cur);
        cur = parent;
        parent = root[cur];
    }

    return cur;
}


void _union(int x, int y) {
    
    int xParent = _find(x);
    int yParent = _find(y);

    if(xParent == yParent) return;

    if(depth[xParent] < depth[yParent]) {
        root[xParent] = yParent;
    } else {
        root[yParent] = xParent;

        if(depth[xParent] == depth[yParent])
            depth[xParent]++;
    }
}

// min heap

struct uvw{
    int u;
    int v;
    int w;
    uvw (int u = 0, int v = 0, int w = 0) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

uvw heap[HMAX];
int hcnt = 0;

void heapPush(uvw x) {

    heap[++hcnt] = x;

    register int idx = hcnt;

    while(idx > 1 && heap[idx].w < heap[idx/2].w) {
        uvw tmp = heap[idx];
        heap[idx] = heap[idx/2];
        heap[idx/2] = tmp;
        idx/=2; 
    }

}

uvw heapPop(){

    if(!hcnt) return uvw(0,0,0);

    uvw ret = heap[1];
    heap[1] = heap[hcnt--];
    register int idx = 1;
    int l, r, n;
    while(1) {
        l = 2*idx;
        r = 2*idx + 1;
        n = 0;

        if(l <= hcnt && heap[idx].w > heap[l].w) n = l;
        if(r <= hcnt && heap[idx].w > heap[r].w && heap[l].w > heap[r].w) n = r;

        if(!n) break;
        uvw tmp = heap[n];
        heap[n] = heap[idx];
        heap[idx] = tmp;
        idx = n;
    }

    return ret;
}



// main()
int N, M;

void init() {

    makeSet();
    for(register int i = 0; i < VMAX; i++) {
        for(register int j = 0; j < VMAX; j++){

        }
    }
}

int kruskal() {

    int ret = 0;

    // select N - 1 edges
    int pu, pv;
    uvw c;
    for(register int i = 1; i < N; i++) {
        while(1) {
            c = heapPop();
            pu = _find(c.u);
            pv = _find(c.v);
            if(pu != pv) break;
        }
        ret += c.w;
        _union(c.u,c.v);

    }

    return ret;


}

int main() {

    init();

    scanf("%d", &N);
    scanf("%d", &M);

    int u,v,w;
    for(register int i = 0; i < M; i++) {
        scanf("%d %d %d",&u, &v, &w);
        heapPush(uvw(u,v,w));
    }

    printf("%d\n",kruskal());
    return 0;
}
