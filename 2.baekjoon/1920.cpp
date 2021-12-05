// 백준 P1920 번 : 수 찾기
// binary search
#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = (int)1e6 + 1;
const int MMAX = (int)1e6 + 1;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N, M;

int arr[NMAX];
int tmp[NMAX];

void mergeSort(int st, int ed) {
    //base case
    if(st >= ed) return;
    int m = (st + ed)/2;
    mergeSort(st,m);
    mergeSort(m+1,ed);

    int l, r, n, idx;
    l = st, r = m + 1;
    idx = st;

    while(l <= m || r <= ed) {
        if(l <= m && (r > ed || arr[l] < arr[r])) {
            n = l++;
        } else {
            n = r++;
        }
        tmp[idx++] = arr[n];
    }

    for(int i = st; i <= ed; i++)
        arr[i] = tmp[i];

}

void sol() {
    scanf("%d",&N);
    for(int i = 0; i < N; i++) scanf("%d",&arr[i]);

    mergeSort(0,N-1);

    
    scanf("%d",&M);
    int key;
    for(int i = 0; i < M; i++) {
        scanf("%d",&key);

        int l = 0, r = N - 1;
        int m;
        bool flag = false;
        while(l <= r) {
            m = (l+r)/2;
            if(arr[m] == key) {
                flag = true;
                break;
            } else if (arr[m] > key) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if(flag) printf("1\n");
        else printf("0\n");

    }

}



int main() {
    
    sol();
    // printf("%d",sol());
    return 0;
}