#include <iostream>
#include <stdlib.h>
#include <vector>
#define mymax(a, b) ((a) > (b) ? (a) : (b))
#define mymin(a, b) ((a) < (b) ? (a) : (b))
#define updateBit(x, a) ((x) | (1 << (a)))
#define checkBit(x, a) ((x) & (1 << (a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 5000000;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N;

int main(void) {

	cin >> N;

	vector<vector<int> > cost(N,vector<int>(3,0));

	for(int i = 0; i < N; i++)
		for(int j = 0; j < 3; j++)
			cin >> cost[i][j];

	vector<vector<int> > mem(N, vector<int>(3,0));

	mem[0][0] = cost[0][0];
	mem[0][1] = cost[0][1];
	mem[0][2] = cost[0][2];

	for(int i = 1; i < N; i++) {
		mem[i][0] = min(mem[i-1][1],mem[i-1][2]) + cost[i][0];
		mem[i][1] = min(mem[i-1][0],mem[i-1][2]) + cost[i][1];
		mem[i][2] = min(mem[i-1][1],mem[i-1][0]) + cost[i][2];
	}

	printf("%d\n",min(min(mem[N-1][0],mem[N-1][1]),mem[N-1][2]));
	
	return 0;
}
