#include <iostream>
#include <cstring>

#define MAXN 101
#define MAXK 100001
using ui = unsigned int;
using ll=long long;
using ull=unsigned long long;

using namespace std;

ui N,K;

ui W[MAXN];
ui V[MAXN];
int mem[MAXN][MAXK];

int dp(ui i, ui k) {
	if(mem[i][k]^-1) return mem[i][k];
	int res = 0;
	if(W[i] > k) {
		res = dp(i-1,k);
	} else {
		int a = dp(i-1,k);
		int b = dp(i-1,k-W[i]) + V[i];
		res = a > b ? a : b;
	}

	return mem[i][k] = res;
}

int main(void) {
	//init
	for(int i = 1; i < MAXN; i++)
		for(int j = 0; j < MAXK; j++)
			mem[i][j] = -1;

	for(int i = 0; i < MAXK; i++)
		mem[0][i] = 0;

	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}

	

	printf("%d\n",dp(N,K));

	return 0;
}