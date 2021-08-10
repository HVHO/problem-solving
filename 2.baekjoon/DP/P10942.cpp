#include <iostream>
#include <stdlib.h>
#define mymax(a, b) ((a) > (b) ? (a) : (b))
#define mymin(a, b) ((a) < (b) ? (a) : (b))
#define updateBit(x, a) ((x) | (1 << (a)))
#define checkBit(x, a) ((x) & (1 << (a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 2001;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N, M;

int num[NMAX];
bool mem[NMAX][NMAX] = {false, };

int main(void) {
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d",&num[i]);
	}

	for(int i = 0; i < N; i++) {
		// expand even len palindrome
		int l = i - 1;
		int r = i;
		for(;0<=l && r < N && num[l] == num[r]; l--&&r++) {
			mem[l][r] = true;
		}
		// expand odd len palindrome
		l = i;
		r = i;
		for(;0<=l && r < N && num[l] == num[r]; l--&&r++){
			mem[l][r] = true;
		}
	}
	
	scanf("%d", &M);
	int st, ed;
	for(int i = 0; i < M; i++) {
		scanf("%d %d",&st,&ed);
		printf("%d\n", mem[st-1][ed-1] ? 1 : 0);
	}

	return 0;
}
