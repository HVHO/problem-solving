#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define VMAX 200002
#define INF 0x12345678

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}

using namespace std;


class heap {

    pair <int, int> heap[2*VMAX];
    int hcnt;

public :

    void init() {
        hcnt = 0;
    }

    bool empty() {
        if(!hcnt) return true;
        return false;
    }

    void push(pair <int, int> a) {

        heap[++hcnt] = a;
        int idx = hcnt;

        while(idx > 1 && heap[idx].second < heap[idx/2].second) {

            myswap(heap[idx],heap[idx/2]);
            idx /= 2;

        }

        return;
    }

    pair <int, int> pop() {

        if(!hcnt) return pair<int,int> (0,0);

        pair <int, int> ret = heap[1];
        heap[1] = heap[hcnt--];

        int idx = 1;
        while(1) {

            int next = 0;
            int left = 2*idx;
            int right = 2*idx + 1;

            if(left <= hcnt) {
                if(heap[left].second < heap[idx].second) next = left;
            }
            if(right <= hcnt) {
                if(heap[right].second < heap[idx].second 
                && heap[right].second < heap[left].second) next = right;
            }

            if(!next) break;

            myswap(heap[next],heap[idx]);
            idx = next;
        }

        return ret;
    }
};


int V, E, K;
int d[VMAX] = {0};
//int p[VMAX] = {0};
vector < pair<int,int> > adjList[VMAX]; // first : v second : w
heap pq;

void dijkstra() {
    int i,j;


    // init
    for(i = 1; i <= V; i++) {
        d[i] = INF;
    }
   //d[K] = 0; 
    pq.init();

    // search

    pq.push(pair<int,int>(K,0));

    while(!pq.empty()) {

        pair <int,int> cur = pq.pop();
        int v = cur.first;
        int w = cur.second;

        if(w >= d[v]) continue;
        d[v] = w;

        for(i = 0; i < adjList[v].size(); i++ ) {
            pair <int, int> next = adjList[v][i];
            int nv = next.first;
            int nw = next.second;

            if(d[nv] > w + nw) {
                //d[nv] = w + nw;
                pq.push(pair<int, int> (nv, w + nw));
            }
        }

    }

    return;
}

int main() {
    int i,j;

    scanf("%d %d" , &V, &E);
    scanf("%d", &K);

    // input
    int u,v,w;
    for(i = 0; i < E; i++) {    
        scanf("%d %d %d", &u, &v, &w );
        adjList[u].push_back(pair<int,int>(v,w));
    }

    // sort
    for(i = 1; i <= V; i++) 
        sort(adjList[i].begin(),adjList[i].end());

    // dijkstra
    dijkstra();

    // print
    for(i = 1; i <= V; i++) {
        if(d[i] == INF) { puts("INF"); continue;}
        printf("%d\n", d[i]);
    }


    return 0;
}
