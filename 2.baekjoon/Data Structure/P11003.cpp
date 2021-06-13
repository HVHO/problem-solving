#include <iostream>
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = (int)5e6;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N,L;


pair<int,int> heap[NMAX + 1]; // val , idx
int h_idx = 0;

void push(int idx, int val) {
    int t_idx = ++h_idx;
    heap[t_idx] = {val, idx}; 

    while(t_idx > 1 && heap[t_idx/2].first > heap[t_idx].first) {
        auto t = heap[t_idx/2];
        heap[t_idx/2] = heap[t_idx];
        heap[t_idx] = t;
        t_idx/=2;
    }
}

pair<int,int> top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[h_idx--];
    int c = 1;
    int n = 0, l , r;
    while(c <= h_idx/2) {
        n = c;
        l = 2*c;
        r = 2*c + 1;
        if(heap[n].first > heap[l].first) n = l;
        if(r <= h_idx && heap[n].first > heap[r].first) n = r;
        if(c==n) break;
        auto t = heap[n];
        heap[n] = heap[c];
        heap[c] = t;
        c = n;
    }
}




int sol() {
    scanf("%d", &N);
    scanf("%d", &L);
    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        push(i, input);
        while(heap[1].second <= (i - L )) pop();


        cout << heap[1].first << " ";
    }

    return 0;
}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base :: sync_with_stdio(false);   
    sol();
    return 0;
}