// 백준 P11657 번 : 타임머신
// bellman-ford
#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))

const int INF = 987654321;
const int MOD = 1e7 + 9;
const int NMAX = (int)501;
const int MMAX = (int)6000;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;


struct EDGE {
  int s,e,w;  
  EDGE(int s = 0, int e = 0, int w = 0) {
      this->s = s;
      this->e = e;
      this->w = w;
  };
};

int N,M;
EDGE edge[MMAX];
int edgeCnt = 0;
int d[NMAX];


// bellman-ford
void bd() {

    d[1] = 0;
    bool flag;
    for(int i = 0; i < N+10; i++) {
        flag = false;
        for(int j = 0; j < M; j++) {
            EDGE c = edge[j];
            if(d[c.s] != INF && (d[c.e] > d[c.s] + c.w)) {
                d[c.e] = d[c.s] + c.w;
                flag = true;
            }
        }
    }

    if(flag) {
        printf("-1\n");
        return;
    }

    for(int i = 2; i <= N; i++)
        if(d[i] != INF) printf("%d\n",d[i]);
        else printf("-1\n");

    return;
}

int sol() {

    scanf("%d %d",&N,&M);

    //init 
    for(int i = 1; i <= N; i++) {
       d[i] = INF; 
    }

    int st, ed, cost; 
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d",&st,&ed,&cost);
        edge[edgeCnt++] = EDGE(st,ed,cost);
    }

    bd();

    return 0;
}


int main() {
    //printf("%d\n",sol());
    sol();
    return 0;
}