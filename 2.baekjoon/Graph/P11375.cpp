// 백준 P11375 번 : 열혈강호
// binary matching
#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = (int)1001;
const int MMAX = (int)1001;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N, M;

bool map[NMAX][MMAX];
int match[NMAX];
int rmatch[MMAX];
bool visit[NMAX];

bool dfs(int a) {
    
    visit[a] = true;

    for(int i = 1; i <= M; i++) {
        if(map[a][i]) {
            if(!rmatch[i] || (!visit[rmatch[i]] && dfs(rmatch[i]))) {
                match[a] = i;
                rmatch[i] = a;
                return true;
            }
        }
    }
    
    return false;
}

int sol() {

    scanf("%d %d",&N,&M);

    int st, cnt, ed;
    for(int i = 0; i < N; i++) {
        scanf("%d",&cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d",&ed);
            map[i+1][ed] = true;
        }
    }

    int ret = 0;
    for(int i = 1; i <= N; i++) {
        for(int i = 0; i <= N; i++)
            visit[i] = false;
        if(dfs(i)) ret++;
    }
    
    return ret;
}



int main() {
    
    // sol();
    printf("%d",sol());
    return 0;
}