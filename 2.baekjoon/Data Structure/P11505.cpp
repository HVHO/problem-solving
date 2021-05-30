#include <iostream>
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 1048576;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N,M,K;
int input[NMAX];
ll segTree[4*NMAX] = {0,};


long long init(int l, int r, int node) {

    if(l==r) {
        return segTree[node] = input[l];
    } 
    int m = (l + r)/2;
    return segTree[node] = (init(l, m, 2*node)*init(m+1,r,2*node+1))%MOD;
}

void update(int idx, int val, int l, int r, int node) {
    // printf("idx %d  val %d l %d r %d node %d\n",idx,val,l,r,node);
    if(l > idx || r < idx) return;
    if(l==r) {
        segTree[node] = val;
        return;
    }
    int m = (l+r)/2;
    update(idx,val,l,m,2*node);
    update(idx,val,m+1,r,2*node+1);
    segTree[node]=(segTree[2*node]*segTree[2*node+1])%MOD;
}

long long query(int l, int r, int nodeL, int nodeR, int node) {
    if(r < nodeL || l > nodeR) return 1;
    if(l <= nodeL && nodeR <= r) return segTree[node];
    int m = (nodeL + nodeR)/2;
    return (query(l,r,nodeL, m, 2*node)*query(l,r,m+1,nodeR,2*node+1))%MOD;
}




int sol() {
    
    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&K);

    for(int i = 0; i < N; i++){
        scanf("%d",&input[i]);
    }
    init(0,N-1,1);

    int a,b,c;
    for(int i = 0; i < M + K; i++) {
        scanf("%d %d %d",&a,&b,&c);
        // printf("%d %d %d\n",a,b,c);
        if(a == 1) {
            update(b-1,c,0,N-1,1);
        } else {
            printf("%lld\n",query(b-1,c-1,0,N-1,1));
        }
    }
    
    return 0;
}



int main() {
    
    sol();
    // printf("%d",sol());
    return 0;
}