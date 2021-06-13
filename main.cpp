#include <iostream>
#include <stdlib.h>
#include <limits.h>
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define mymin(a,b) ((a) < (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 5000000;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N,L;


pair<int,int> deque[2*NMAX]; // val, idx
int front = 0, rare = 0; 


int sol() {
    scanf("%d", &N);
    scanf("%d", &L);
    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        if(front < rare && deque[front+1].second <= (i - L)) front++;
        while(front < rare && deque[rare].first >= input) {
            rare--;
        }
        deque[++rare] = {input, i};
        cout << deque[front+1].first << " ";
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