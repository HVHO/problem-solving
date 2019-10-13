#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 202
#define INF 0x12345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))

using namespace std;


// disjoint set
int root[MAX];
int depth[MAX];

void makeSet() {
    for(register int i = 0; i < MAX; i++) {
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

// main()
int N, M;

void init() {

    for(register int i = 0; i < MAX; i++) {
        for(register int j = 0; j < MAX; j++){

        }
    }
}


int main() {

    init();

    scanf("%d", &N);
    scanf("%d", &M);

    makeSet();
    register int tmp;
    for(register int i = 0; i < N; i++) 
        for(register int j = 0; j < N; j++) {
            //scanf("%d", &map[i][j]);
            scanf("%d", &tmp);
            if(tmp) _union(i,j);
        }
    
    //printf("1\n");
    int p,c;
    scanf("%d",&p);
    p--;
    for(register int i = 1; i < M; i++) {
        scanf("%d",&c);
        c--;
        if(_find(c) != _find(p)) {
            printf("NO\n"); return 0;
        }
        p = c;
    }
   
    printf("YES\n");

    return 0;
}
